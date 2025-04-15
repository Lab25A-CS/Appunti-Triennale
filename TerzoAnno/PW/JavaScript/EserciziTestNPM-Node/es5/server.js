const express = require("express")

const app = express()

app.use(express.json())

app.get("/", (req, res) => {
    res.send("Hello World")
})

app.get("/ciao",(req,res)=>{
    console.log("NOME:"+req.query.nome)
    res.send("Ciao "+req.query.nome)
})

app.get("/user/:id",(req,res)=>{
    console.log("USER ID:"+req.params.id)
    res.send("Ciao User ID"+req.params.id)
})

app.post("/user",(req,res)=>{
    console.log(req.body);
})

app.listen(3000, () => {
    console.log("Server is running on port 3000")
})
