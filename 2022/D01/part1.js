lines = []
require("fs")
  .readFileSync("input.txt").toString()
  .split(/\r?\n/)
  .forEach( (line) => {
    lines.push(line)
  }
);

let max_cal = 0, act_cal = 0
lines.map( (line) => {
  if(line == "") {
    line = parseInt(line)
    if(max_cal < act_cal) {
      max_cal = act_cal
    }
    act_cal = 0
  } else {
    act_cal += parseInt(line)
  }
})

console.log(max_cal)
