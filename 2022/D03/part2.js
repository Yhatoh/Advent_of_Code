lines = []
require("fs")
  .readFileSync("input.txt").toString()
  .split(/\r?\n/)
  .forEach( (line) => {
    lines.push(line)
  }
);

function charToPoint(c) {
	c = c.charCodeAt(0)
	if(c > "Z".charCodeAt(0))
		return c - "a".charCodeAt(0) + 1
	return c - "A".charCodeAt(0) + 27
}

let sum = 0
first = new Set()
second = new Set()
third = new Set()
let cont = 0
let flag = 0
lines.map((line) => {
	line.split("").map((c) => {
		if(cont === 0) {
			first.add(c)
		} else if(cont === 1) {
			second.add(c)
		} else {
			if(first.has(c) && second.has(c)) third.add(c)
		}
	})
	if(cont == 2) {
		cont = 0
		flag = 1
	} else cont++
	
	if(flag === 1) {
		flag = 0
		third.forEach((c) => {
			sum += charToPoint(c)
		})
		first = new Set()
		second = new Set()
		third = new Set()
	}
})

console.log(sum)