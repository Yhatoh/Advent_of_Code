lines = []
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        //lines.push(line)
        lines.push(line)
    }
);

let n = lines.length
let m = lines[0].length

let sum = 2 * n + m * 2 - 4
for(let i = 1; i < n - 1; i++) {
	for(let j = 1; j < m - 1; j++) {
		let tree = parseInt(lines[i][j])
		let right = true
		let left = true
		let top = true
		let bot = true
		for(let k = i + 1; k < n; k++) {
			if(tree <= parseInt(lines[k][j])) {
				right = false
			}
		} 
		for(let k = i - 1; k >= 0; k--) {
			if(tree <= parseInt(lines[k][j])) {
				left = false
			}
		} 
		
		for(let k = j + 1; k < m; k++) {
			if(tree <= parseInt(lines[i][k])) {
				top = false
			}
		} 
		
		for(let k = j - 1; k >= 0; k--) {
			if(tree <= parseInt(lines[i][k])) {
				bot = false
			}
		} 
		
		if(right || bot || left || top) sum += 1
	}
}

console.log(sum)