lines = [[[2]], [[6]]]
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        if(line !== "") {
			lines.push(JSON.parse(line))
		}
    }
);

function isNumber(n) { return typeof n === "number"}

function compare(l1, l2) {
	while(l1.length > 0 && l2.length > 0) {
		let e1 = l1.shift()
		let e2 = l2.shift()
		if(isNumber(e1) && isNumber(e2)) {
			if(e1 > e2) return 0
			else if(e2 > e1) return 1
		} else if(!isNumber(e1) && isNumber(e2)) {
			let r = compare(e1.slice(), [e2])
			if(r === 1) return 1
			else if(r === 0) return 0
		} else if(isNumber(e1) && !isNumber(e2)) {
			let r = compare([e1], e2.slice())
			if(r === 1) return 1
			else if(r === 0) return 0
		} else {
			let r = compare(e1.slice(), e2.slice())
			if(r === 1) return 1
			else if(r === 0) return 0
		}
	}
	
	if(l2.length > 0) return 1
	if(l1.length > 0) return 0
	
	return 2
}

let sum = 0
let index = 1

lines.sort((a, b) => {
	if(compare(a.slice(), b.slice()) === 1) {
		return -1
	} else if(compare(a.slice(), b.slice()) === 0) {
		return 1
	} else {
		return 0
	}
})

let res = 1

for(let i = 0; i < lines.length; i++) {
	if( JSON.stringify(lines[i]) == JSON.stringify([[2]]) || 
		JSON.stringify(lines[i]) == JSON.stringify([[6]])){
		res *= i + 1
	}
}

console.log(res)