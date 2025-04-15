"use strict"

const myUrl = "https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY"
const request = new XMLHttpRequest()

request.open('GET',myUrl,false) //if code is Syn then use False instead of True
request.send(null)
console.log(request.responseText)