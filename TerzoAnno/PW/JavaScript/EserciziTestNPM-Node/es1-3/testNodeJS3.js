"use strict"

const http=require("http")
const fs = require("fs")

const server=http.createServer((req,res)=>{
    console.log("request received")
    console.log(req.url)
    fs.readFile(__dirname+req.url,(err,data)=>{
        if(err){
            res.writeHead(404)
            res.end("Pagina non trovata")
        }else{
            res.writeHead(200)
            res.end(data)
        }
    })
})

server.listen(8080,"localhost",()=>{
    console.log("Server partito sulla porta 8080")
})