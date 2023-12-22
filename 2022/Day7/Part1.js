lines = []
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        //lines.push(line)
        lines.push(line)
    }
);

function insert(js, profundity, key, value) {
	if(profundity.length === 0) {
		js[key] = value
		return
	}
	let act_dir = profundity[0]
	let new_profundity = profundity.slice()
	new_profundity.shift()
	insert(js[act_dir], new_profundity, key, value)
}

var sum = 0

function count(js) {
	let local_sum = 0
	Object.keys(js).map((key) => {
		if(!isNaN(js[key])) {
			local_sum += js[key]
		} else {
			local_sum += count(js[key])
		}
	})
	if(local_sum <= 100000) {
		sum += local_sum
	}
	return local_sum
}

dir = {}

profundity = []

lines.shift()
lines.map((line) => {
	if(line.indexOf("$") > -1) {
		splitted = line.split(" ")
		if(splitted[1] === "cd") {
			if(splitted[2] === "..") profundity.pop()
			else profundity.push(splitted[2])
		}
	} else {
		splitted = line.split(" ")
		if(splitted[0] === "dir")
			insert(dir, profundity.slice(), splitted[1], {})
		else
			insert(dir, profundity.slice(), splitted[1], parseInt(splitted[0]))
	}
})
count(dir)
console.log(sum)