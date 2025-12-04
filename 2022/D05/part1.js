lines = []
require("fs")
  .readFileSync("input.txt").toString()
  .split(/\r?\n/)
  .forEach( (line) => {
    lines.push(line)
  }
);

function pos_stacks(num_stack) {
	ret = []
	for(let i = 0; i < num_stack.length; i++)
		if(num_stack[i] != " ") ret.push(i)
	return ret
}

stacks = []
moves = []

let flag = 0
lines.map((line) => {
	if(flag == 0) {
		if(line.indexOf("1") > -1) {
			flag = 1
		}
		stacks.push(line)
	} else {
		if(line == "") return
		moves.push(line)
	}
})

nums_stacks = pos_stacks(stacks[stacks.length - 1])
stacks.pop()

list_stacks = Array.from({length: nums_stacks.length}, (_) => [])

stacks.reverse().map((stack) => {
	for(let i = 0; i < stack.length; i++) {
		let which_stack = nums_stacks.indexOf(i)
		if(nums_stacks.indexOf(i) > -1 && " []".indexOf(stack[i]) == -1) {
			list_stacks[which_stack].push(stack[i])
			which_stack++
		}
	}
})

moves
	.map((move) => move.split(/[a-z ]+/g).slice(1).map((i) => parseInt(i) - 1))
	.map((move) => {
		[...Array(move[0] + 1).keys()]
			.map((_) => {
				list_stacks[move[2]]
					.push(list_stacks[move[1]].pop())
			})	
	})
console.log(list_stacks.map((stack) => stack.at(-1)).join(""))