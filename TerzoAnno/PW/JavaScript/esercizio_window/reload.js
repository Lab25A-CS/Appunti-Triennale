"use strict"

function ricaricaPagina(secondi){
    setInterval(function(){
        location.reload()
    },secondi *1000)
}

ricaricaPagina(5)