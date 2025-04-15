"use strict"

/**
 * aggiunge elemento alla lista
 */
function addElement(){
    let otherEl = ["dio","davide","lucio battisti","SHREK"]
    let list = document.getElementById("list")
    let item = document.createElement("li")
    let randomThing = otherEl[Math.floor(Math.random()*otherEl.length)]
    let text = document.createTextNode(randomThing)
    item.appendChild(text)
    list.appendChild(item)
}

let picture = ["bg-cangat.jpg","bg-cani.jpg","bg-gatti.jpg"]
let picIndex=0
let img = document.querySelectorAll("img")[0]

function changePicture(){
    img.setAttribute("src",picture[picIndex])
    

}

let button = document.getElementById("what-else")
button.addEventListener("click",addElement)
button.addEventListener("click",changePicture)