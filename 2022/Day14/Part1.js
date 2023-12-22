lines = []
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        //lines.push(line)
        lines.push(line)
    }
);

let max_x = 0
let min_x = 10000000000000
let max_y = 0

paths = 
	lines.map((line) => 
		line.split(" -> ")
			.map((e) => 
				e.split(",").map((c) => parseInt(c))
		)
	)

paths.map((path) => {
	path.map(([x, y]) => {
		if(x > max_x) max_x = x
		if(x < min_x) min_x = x
		if(y > max_y) max_y = y
	})
})

grid = []
for(let i = 0; i <= max_y; i++) {
	row = []
	for(let j = 0; j < max_x - min_x + 1; j++) {
		row.push(".")
	}
	grid.push(row)
}

for(let i = 0; i < paths.length; i++) {
	for(let j = 1; j < paths[i].length; j++) {
		let [prev_x, prev_y] = paths[i][j - 1]
		let [act_x, act_y] = paths[i][j]
		if(prev_x === act_x) {
			if(prev_y > act_y) {
				while(prev_y >= act_y) {
					grid[prev_y][prev_x - min_x] = "#"
					prev_y--
				}
			} else {
				while(prev_y <= act_y) {
					grid[prev_y][prev_x - min_x] = "#"
					prev_y++
				}
			}
		} else if(prev_y === act_y) {
			
			if(prev_x > act_x) {
				while(prev_x >= act_x) {
					grid[prev_y][prev_x - min_x] = "#"
					prev_x--
				}
			} else {
				while(prev_x <= act_x) {
					grid[prev_y][prev_x - min_x] = "#"
					prev_x++
				}
			}
		}
	}
}

function check(grid) {
	let [start_x, start_y] = [500 - min_x, 0]
	while(start_y < max_y) {
		if(grid[start_y + 1][start_x] === ".") {
			start_y++
		} else if(start_x > 0 && grid[start_y + 1][start_x - 1] === ".") {
			start_y++
			start_x--
		} else if(start_x < max_x - min_x + 1 && grid[start_y + 1][start_x + 1] === ".") {
			start_y++
			start_x++
		} else {
			break
		}
	}
	if(start_y === max_y) return 1
	else return 0
}

let cont = 0
while(check(grid) === 0) {
	let [start_x, start_y] = [500 - min_x, 0]
	while(start_y < max_y) {
		if(grid[start_y + 1][start_x] === ".") {
			start_y++
		} else if(start_x > 0 && grid[start_y + 1][start_x - 1] === ".") {
			start_y++
			start_x--
		} else if(start_x < max_x - min_x + 1 && grid[start_y + 1][start_x + 1] === ".") {
			start_y++
			start_x++
		} else {
			break
		}
	}
	grid[start_y][start_x] = "O"
	cont++
}

//console.log(grid.map((e) => e.join("")).join("\n"))
console.log(cont)