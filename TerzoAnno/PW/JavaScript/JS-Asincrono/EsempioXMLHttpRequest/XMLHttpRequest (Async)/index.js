"use strict"

const myUrl = "https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY"
const request = new XMLHttpRequest()

request.open('GET',myUrl,true) //if code is Async then use True instead of False
request.send(null)

request.onreadystatechange = function(){
    if (this.readyState == 4 && this.status == 200){
        console.log(this.responseText)
    }
}