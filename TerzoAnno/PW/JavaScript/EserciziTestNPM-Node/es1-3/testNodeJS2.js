'use strict'

const fs = require("fs")

const file = fs.readFileSync("input.txt","utf-8")//funzione sincrona
console.log("Ho letto:\n" + file)

fs.readFile("input.txt","utf-8",(err,data)=>{//funzione asincrona   
    if(err){
        console.log("Errore: " + err)
    }else{
        console.log("CallBack Asincrono")
        console.log("Ho letto:\n" + data)
    }
})
