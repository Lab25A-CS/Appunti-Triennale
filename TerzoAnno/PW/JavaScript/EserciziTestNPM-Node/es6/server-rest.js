const fs = require("fs")
const express = require("express")
const cors = require("cors")

const data_json = fs.readFileSync(__dirname+"/libri.json")
const data = JSON.parse(data_json)

console.log(data)

const app = express()

app.use(cors())

app.get("/",(req,res)=>{
    res.sendFile(__dirname+"/index-rest.html")
})

app.get("/libri/",(req,res)=>{
    res.json(data)
    console.log("Data:")
})

app.get("/libri/:id",(req,res)=>{
    const id = req.params.id
    data.forEach((element)=>{
        if(element.id == id){
            const resp = {
                status:"ok",
                data:element,
            };
            res.json(resp)
        }
    });
    res.status(404).json({status:"error",message:"Not Found",data:null}) 
})

app.listen(3000,()=>{
    console.log("Server is running on port 3000")
})