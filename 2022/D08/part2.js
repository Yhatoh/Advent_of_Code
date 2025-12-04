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

let sum = 0
for(let i = 1; i < n - 1; i++) {
	for(let j = 1; j < m - 1; j++) {
		let tree = parseInt(lines[i][j])
		let right = 1
		let left = 1
		let top = 1
		let bot = 1
		let k
		for(k = i + 1; k < n; k++) {
			if(tree <= parseInt(lines[k][j])) {
				break
			}
			right++
		} 
		if(k == n) right--
		for(k = i - 1; k >= 0; k--) {
			if(tree <= parseInt(lines[k][j])) {
				break
			}
			left++
		} 
		if(k == -1) left--
		for(k = j + 1; k < m; k++) {
			if(tree <= parseInt(lines[i][k])) {
				break
			}
			top++
		} 
		if(k == m) top--
		for(k = j - 1; k >= 0; k--) {
			if(tree <= parseInt(lines[i][k])) {
				break
			}
			bot++
		} 
		if(k == -1) bot--
		if(top * bot * left * right > sum) sum = top * bot * left * right
	}
}

console.log(sum)