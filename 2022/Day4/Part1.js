lines = []
require("fs")
  .readFileSync("input.txt").toString()
  .split(/\r?\n/)
  .forEach( (line) => {
    lines.push(line)
  }
);

let count = 0
lines.map((line) => {
	line = line.split(",")
	L1 = parseInt(line[0].split("-")[0])
	R1 = parseInt(line[0].split("-")[1])
	L2 = parseInt(line[1].split("-")[0])
	R2 = parseInt(line[1].split("-")[1])
	
	if(L1 <= L2 && R2 <= R1) count++
	else if(L1 >= L2 && R2 >= R1) count++
})

console.log(count)