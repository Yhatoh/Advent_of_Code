lines = []
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        //lines.push(line)
        lines.push(line)
    }
);

grid = lines.map((line) => line.split("").map((pos) => 100000000000000000))

let start_x = 0
let start_y = 0
let end_x = 0
let end_y = 0

for(let i = 0; i < lines.length; i++) {
	if(lines[i].indexOf("S") > -1) {
		start_x = i
		start_y = lines[i].indexOf("S")
	}
	if(lines[i].indexOf("E") > -1) {
		end_x = i
		end_y = lines[i].indexOf("E")
	}
}
queue = [[start_x, start_y]]
grid[start_x][start_y] = 0

let n = lines.length
let m = lines[0].length
while(queue.length > 0) {
	let [x, y] = queue.shift()
	let char_act = lines[x][y]
	if(x > 0) {
		let char_next = lines[x - 1][y]
		if(char_act === "S") {
			if(grid[x][y] + 1 < grid[x - 1][y]) {
				grid[x - 1][y] = grid[x][y] + 1
				queue.push([x - 1, y])
			}
		} else {
			if(char_next === "E" && char_act === "z") {
				grid[x - 1][y] = (grid[x][y] + 1 < grid[x - 1][y] ? grid[x][y] + 1 : grid[x - 1][y])
			} else if(char_next !== "S" && char_next !== "E") {
				if(char_next.charCodeAt(0) <= char_act.charCodeAt(0) + 1) {
					if(grid[x][y] + 1 < grid[x - 1][y]) {
						grid[x - 1][y] = grid[x][y] + 1
						queue.push([x - 1, y])
					}
				}
			}
		}
	}
	if(x < n - 1) {
		let char_next = lines[x + 1][y]
		if(char_act === "S") {
			if(grid[x][y] + 1 < grid[x + 1][y]) {
				grid[x + 1][y] = grid[x][y] + 1
				queue.push([x + 1, y])
			}
		} else {
			if(char_next === "E" && char_act === "z") {
				grid[x + 1][y] = (grid[x][y] + 1 < grid[x + 1][y] ? grid[x][y] + 1 : grid[x + 1][y])
			} else if(char_next !== "S" && char_next !== "E") {
				if(char_next.charCodeAt(0) <= char_act.charCodeAt(0) + 1) {
					if(grid[x][y] + 1 < grid[x + 1][y]) {
						grid[x + 1][y] = grid[x][y] + 1
						queue.push([x + 1, y])
					}
				}
			}
		}
	}
	if(y > 0) {
		let char_next = lines[x][y - 1]
		if(char_act === "S") {
			if(grid[x][y] + 1 < grid[x][y - 1]) {
				grid[x][y - 1] = grid[x][y] + 1
				queue.push([x, y - 1])
			}
		} else {
			if(char_next === "E" && char_act === "z") {
				grid[x][y - 1] = (grid[x][y] + 1 < grid[x][y - 1] ? grid[x][y] + 1 : grid[x][y - 1])
			} else if(char_next !== "S" && char_next !== "E") {
				if(char_next.charCodeAt(0) <= char_act.charCodeAt(0) + 1) {
					if(grid[x][y] + 1 < grid[x][y - 1]) {
						grid[x][y - 1] = grid[x][y] + 1
						queue.push([x, y - 1])
					}
				}
			}
		}
	}
	if(y < m - 1) {
		let char_next = lines[x][y + 1]
		if(char_act === "S") {
			if(grid[x][y] + 1 < grid[x][y + 1]) {
				grid[x][y + 1] = grid[x][y] + 1
				queue.push([x, y + 1])
			}
		} else {
			if(char_next === "E" && char_act === "z") {
				grid[x][y + 1] = (grid[x][y] + 1 < grid[x][y + 1] ? grid[x][y] + 1 : grid[x][y + 1])
			} else if(char_next !== "S" && char_next !== "E") {
				if(char_next.charCodeAt(0) <= char_act.charCodeAt(0) + 1) {
					if(grid[x][y] + 1 < grid[x][y + 1]) {
						grid[x][y + 1] = grid[x][y] + 1
						queue.push([x, y + 1])
					}
				}
			}
		}
	}
}

console.log(grid[end_x][end_y])