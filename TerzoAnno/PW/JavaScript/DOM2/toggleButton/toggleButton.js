let showHelloWorld = false;
function toggleHelloWorld() {
    if (!showHelloWorld) {
      document.getElementById("prova").innerHTML = "<h1>CIAO</h1>";
    } else {
      document.getElementById("prova").innerHTML = "";
    }
    showHelloWorld = !showHelloWorld;
  }