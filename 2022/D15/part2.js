lines = []
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        //lines.push(line)
        lines.push(line)
    }
);


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

for(let y_obj = 0; y_obj <= 4000000; y_obj++) {
	hash = []
	coords.map(([x1, y1, x2, y2]) => {
		let exp = Math.abs(x1 - x2) + Math.abs(y1 - y2)
		let dist = Math.abs(y1 - y_obj)
		if(exp >= dist) {
			let diff = exp - dist
			hash.push([x1 - diff, x1 + diff])
		}
	})
	hash.sort(([x1, y1], [x2, y2]) => {
		if(x1 === x2) {
			return y1 - y2
		}
		
		return x1 - x2
	})
	
	let [l, r] = hash[0]
	if(l === 1) {
		console.log(0 * 4000000 + y_obj)
	}
	let flag = false
	for(let i = 1; i < hash.length; i++) {
		let [l_p, r_p] = hash[i]
		if(l_p > r) {
			console.log((r + 1) * 4000000 + y_obj)
			flag = true
			break
		}
		
		r = Math.max(r_p, r)
	}
	if(flag) break
}

//console.log(Array.from(hash).sort((a, b) => a - b))