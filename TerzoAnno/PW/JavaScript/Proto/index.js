"use strict"

function Student(name,age){
    this.name = name
    this.age = age
    /*
    this.sayName = function(){
        console.log("Sono"+this.name)
    }*/
    
}
Student.prototype.sayName = function(){console.log("Io sono "+this.name)}
Student.prototype.university = "Tor Vergata"

let pippo = new Student("Pippo",20)
let pluto = new Student("Pluto",150)
let topolino = new Student("Topolino",35)

pippo.sayName()
pluto.sayName()
topolino.sayName()


