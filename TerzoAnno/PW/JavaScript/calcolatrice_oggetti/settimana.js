let giorno = [
	"lunedi",
	"martedi",
	"mercoledi",
	"giovedi",
	"venerdi",
	"sabato",
	"domenica",
]

//let x = prompt("America");
let x = "no"
if( x == "si"){
	// giorno[0] = "domenica"
	// giorno[giorno.length-1] = "lunedi"
	giorno.unshift(giorno.pop())
	console.log("Il primo giorno è " + giorno[0])
	console.log(giorno)
}else{
	console.log("Il primo giorno è " + giorno[0])
}

giorno.forEach(function(x){console.log(x)}) //for elementi in giorno
//giorno.forEach( (x)=>console.log(x))  stessa cosa con arrow funxtion

function esisteElemento(arr,el){
	return arr.indexOf(el) !== -1
}
let utenti = ["mario","giovanna","pippo"]
utenti.map((item,index,array)=> item.toUpperCase())

console.log(utenti)