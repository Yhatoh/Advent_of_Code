lines = []
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        //lines.push(line)
        lines.push(line)
    }
);

let y_obj = 2000000

coords = lines
			.map((line) => 
					line
						.replace("Sensor at x=","")
						.replace(", y=", " ")
						.replace(": closest beacon is at x=", " ")
						.replace(", y=", " ")
						.split(" ")
						.map((e) => parseInt(e)))

//console.log(coords)

let hash = new Set()

coords.map(([x1, y1, x2, y2]) => {
	let exp = Math.abs(x1 - x2) + Math.abs(y1 - y2)
	let dist = Math.abs(y1 - y_obj)
	if(exp >= dist) {
		let diff = exp - dist
		if(x1 !== x2) hash.add(x1)
		let left = 1
		let right = 1
		for(let i = 0; i < diff; i++) {
			if(y2 !== y_obj || x2 !== x1 - left) hash.add(x1 - left)
			if(y2 !== y_obj || x2 !== x1 + right) hash.add(x1 + right)
			left++
			right++
		}
	}
})

//console.log(Array.from(hash).sort((a, b) => a - b))
console.log(hash.size)