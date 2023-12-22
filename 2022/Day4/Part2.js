lines = []
require("fs")
  .readFileSync("input.txt").toString()
  .split(/\r?\n/)
  .forEach( (line) => {
    lines.push(line)
  }
);

function range(size, startAt = 0) {
    return [...Array(size).keys()].map(i => i + startAt)
}

let count = 0
lines.map((line) => {
	line = line.split(",")
	
	let [L1, R1] = line[0].split("-").map((e) => parseInt(e))
	let [L2, R2] = line[1].split("-").map((e) => parseInt(e))
	I1 = range(R1 - L1 + 1, L1)
	I2 = range(R2 - L2 + 1, L2)
	
	let s = new Set()
	I1.map((i) => s.add(i))
	let flag = 0
	I2.map((i) => {
		if(s.has(i) && flag == 0) {
			flag = 1
			count++
		}
	})
})

console.log(count)