function intervallo(){
    let i=0
    const inter = setInterval(function(){
        console.log("Ciao")
        i++
        if (i == 4){
            clearInterval(inter)
        }
    },5000)
}

intervallo()


