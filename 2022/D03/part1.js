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
lines.map((line) => {
	first = new Set()
	both = new Set()
	let cont = 0
	line.split("").map((c) => {
		if(cont < line.split("").length / 2) {
			first.add(c)
		} else {
			if(first.has(c)) both.add(c)
		}
		cont++
	})
	both.forEach((c) => {
		sum += charToPoint(c)
	})
})

console.log(sum)