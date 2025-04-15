"use strict";

let bgWhite = true;

let body = document.getElementsByTagName("body")[0];

let refreshRate = 1000;
let interval



let capDiv = document.getElementById("prova2");
capDiv.addEventListener("click", function () {
  alert("Hai vinto un pisello NEGRO");
  refreshRate /= 2;
  clearInterval(interval)
  interval = setInterval(refresh, refreshRate);
});

/*Sposta il div casualmente all'interno di tutta la pagina, ogni colta che si ricarica la pagina*/
// let randTop = parseInt(Math.random()*window.innerHeight)
// let randLeft = parseInt(Math.random()*window.innerWidth)
// capDiv.style.marginTop=randTop+"px"
// capDiv.style.marginLeft=randLeft+"px"

/*stessa cosa, pero cambia ogni secondo*/
function refresh() {
  let randTop = parseInt(Math.random() * window.innerHeight);
  let randLeft = parseInt(Math.random() * window.innerWidth);
  capDiv.style.marginTop = randTop + "px";
  capDiv.style.marginLeft = randLeft + "px";
  /*effetto strobo */
  if (bgWhite) {
    body.style.backgroundColor = "blue";
    capDiv.style.backgroundColor = "red";
  } else {
    body.style.backgroundColor = "red";
    capDiv.style.backgroundColor = "blue";
  }
  bgWhite = !bgWhite;
}
interval = setInterval(refresh, refreshRate);
