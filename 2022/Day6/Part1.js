lines = []
require("fs")
    .readFileSync("input.txt").toString()
    .split(/\r?\n/)
    .forEach( (line) => {
        //lines.push(line)
        lines.push(line)
    }
);

let s = []
let index = 0
let list = lines[0]
for(let i = 0; i < list.length; i++) {
	if(s.indexOf(list[i]) > -1) {
		while(s.indexOf(list[i]) > -1) {
			s.shift()
		}
		s.push(list[i])
	} else {
		s.push(list[i])
	}
	if(s.length == 4) {
		index = i
		break
	}
}

console.log(index + 1)
