'use strict';

let calc = {
	insert(a,b) {
		this.a=a;
		this.b=b;
	},
	add(){
		return this.a+this.b;
	},
	sub(){
		return this.a-this.b;
	},
	mul(){
		return this.a*this.b;
	},
	div(){
		return this.a/this.b;
	}

}
calc.insert(1,5)
console.log(calc.add())
function User(name){
	this.name = name;
	this.isAdmin = false;
}

let u1 = new User("pippo")

console.log(u1)
let u2 = new User("DIO")
console.log(u2)

let v = "ciao"
console.log(v.toUpperCase())

let array = ["dio","cane",42]
console.log(array)
array.pop()
console.log(array)

//array.length = 0
array[10] = "Pippo"
console.log(array)
delete array[10]
console.log(array)
array.length = 2
console.log(array)
