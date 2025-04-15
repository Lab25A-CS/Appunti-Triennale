let a = ["mario","pippo","giovanna","ferdinando"]

//parte 1 -> tutti gli elementi in maiuscolo
let b = a.map((item,index,a) => item.toUpperCase())
console.log(b)

// parte 2 -> Dr prima di tutti i nomi
let c = a.map((item,index,a)=>item.replace(item,"Dr."+item ))
console.log(c)

// parte 3 -> Ritornare l'elemento più lungo
let d = a.map((item,index,a)=>item+":"+item.length)
console.log(d)
let d2 = d[a.length-1]
console.log(d2)
