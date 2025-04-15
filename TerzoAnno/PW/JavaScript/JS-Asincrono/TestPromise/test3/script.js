function orderExec(resolve,reject){
    console.log("Pizza ordered...")
    resolve("Ecco la pizza")
}

let orderPizza = new Promise(orderExec)
orderPizza.then(console.log)
console.log("Waiting for pizza")

//ordini dichiarazioni stampate 
// 1 : Pizza ordered
// 2 : Waiting for pizza
// 3 : Ecco la pizza