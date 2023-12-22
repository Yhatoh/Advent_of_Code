lines = []
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        //lines.push(line)
        lines.push(line)
    }
);

let cycle = 0
let X = 1
let signal = 0
let cycles = [20, 60, 100, 140, 180, 220]
let index = 0
lines.map((line) => {
	line = line.split(" ")
	let instr = line[0]
	if(instr === "noop") {
		cycle++
		index = cycles.indexOf(cycle)
		if(index > -1) {
			signal += cycles[index] * X
		}
	} else {
		cycle++
		index = cycles.indexOf(cycle)
		if(index > -1) {
			signal += cycles[index] * X
		}
		cycle++
		index = cycles.indexOf(cycle)
		if(index > -1) {
			signal += cycles[index] * X
		}
		X += parseInt(line[1])
	}
})

console.log(signal)