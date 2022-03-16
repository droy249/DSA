// Types of primitive variables in Javascript:
// 1. Objects

let person = {
    name: 'Mosh',
    age: 30
}

// Dot Notation (preferred)
person.name = 'John'
console.log(person.name) // Prints John

// Bracket Notation
let selection = 'name';
person[selection] = 'Mary'
console.log(person.name) // Prints Mary

// 2. Arrays

let selectedColors = ['red', 'blue']; 
selectedColors[2] = 'green';
console.log(selectedColors);