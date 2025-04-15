function buttonExec(resolve,reject){
    let btn = document.getElementById("premi")
    btn.addEventListener("click",resolve)
    setTimeout(reject, 5000);
}

let betterClick = new Promise(buttonExec)

betterClick
.then(function(){console.log("opzione A")})
.catch(function(){console.log("opzione B")});