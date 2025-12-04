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

var total_size = 8000000000
var total = 70000000
var required = 30000000
var unused = 0

function nothing(local_sum) {
	return local_sum
}

function comp(local_sum) {
	if(local_sum + unused >= required && local_sum < total_size) {
		total_size = local_sum
	}
	return local_sum
}

function count(js, fun) {
	let local_sum = 0
	Object.keys(js).map((key) => {
		if(!isNaN(js[key])) {
			local_sum += js[key]
		} else {
			local_sum += count(js[key], fun)
		}
	})
	
	return fun(local_sum)
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
console.log(nothing)
unused = total - count(dir, nothing)
count(dir, comp)
console.log(total_size)