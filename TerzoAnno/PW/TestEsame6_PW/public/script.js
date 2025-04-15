let jsonData = []

async function load(){
    let resp_json = await fetch("http://localhost:3000/articoli")
    jsonData = await resp_json.json()

    let main = document.querySelector("main")
    jsonData.forEach((el)=>{
        sec = document.createElement("section")
        sec.style.className = "section_class"
        sec.innerHTML = `
            <h2>${el.titolo}</h2>
            <p>${el.contenuto}</p>
        `
        sec.style.textAlign = "center"
        sec.style.margin = "2px auto"
        sec.style.height = "33%"
        main.appendChild(sec)
    })
}
load()

const btnFooter = document.getElementById("open")
const close = document.getElementById("close")
const overlay = document.getElementById("overlay")

btnFooter.addEventListener("click", ()=>{
    
    overlay.style.display = "flex"
})

close.addEventListener("click", ()=>{
    
    overlay.style.display = "none"
})