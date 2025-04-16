"use strict";
async function load() {
  const res = await fetch("http://localhost:3000/persone");
  const resp_json = await res.json();
  const persone = resp_json.data;

  const colonna1 = document.getElementsByClassName("colonna1");
  console.log(colonna1);
  const ul = document.createElement("ul");
  persone.forEach((element) => {
    const li = document.createElement("li");
    li.innerHTML = element.nome + " " + element.cognome;
    li.addEventListener("click", () => {
      alert(
        "Nome: " + element.nome + " " + element.cognome + ",Età: " + element.età
      );
    });
    li.style.cursor = "pointer";
    ul.appendChild(li);
  });
  colonna1[0].appendChild(ul);
}

load();

const btn = document.querySelector("button")
const body = document.querySelector("body")
const link = document.querySelectorAll("a")
console.log(link)
btn.addEventListener("click",()=>{
    body.style.backgroundColor = "#00796b"
    link.forEach((el)=>{
        el.style.color = "#313131"
    })

    
})