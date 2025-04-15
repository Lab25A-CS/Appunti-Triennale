const dayjs = require("dayjs") //modulo per la data e il tempo, vedi output del codice

const myLog = function(msg){
    console.log(msg)
}

const myLogTime = function(msg){
    console.log(dayjs().format() + " " + msg)
}

exports.cl = myLog
exports.clt = myLogTime