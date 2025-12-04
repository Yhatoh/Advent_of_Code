lines = []
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        if(line !== "") {
			if(lines.length === 0) {
				lines.push([JSON.parse(line)])
			} else if(lines[lines.length - 1].length === 1) {
				lines[lines.length - 1].push(JSON.parse(line))
			} else {
				lines.push([JSON.parse(line)])
			}
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
			let r = compare(e1, [e2])
			if(r === 1) return 1
			else if(r === 0) return 0
		} else if(isNumber(e1) && !isNumber(e2)) {
			let r = compare([e1], e2)
			if(r === 1) return 1
			else if(r === 0) return 0
		} else {
			let r = compare(e1, e2)
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

lines.map(([l1, l2]) => {
	if([1, 2].indexOf(compare(l1, l2)) > -1) { 
		sum += index
	}
	index++
})

console.log(sum)