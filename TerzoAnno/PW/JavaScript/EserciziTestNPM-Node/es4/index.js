require("dotenv").config()

const colors = require("colors")

const {cl,clt} = require("./log")

cl("Ciao") //custom log -> richiama la funzione myLog del file log.js
clt("Ciao 3") // custom log time -> richiama la funzione myLogTime del file log.js

//console.log(dayjs().format())
console.log("Hello from index.js".red)
console.log("Il mio DB è " + process.env.DB_URL)