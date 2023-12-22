lines = []
require("fs")
  .readFileSync("input.txt").toString()
  .split(/\r?\n/)
  .forEach( (line) => {
    lines.push(line)
  }
);

cals = []
let act_cal = 0
lines.map( (line) => {
  if(line == "") {
    cals.push(act_cal)
    act_cal = 0
  } else {
    act_cal += parseInt(line)
  }
})

cals.sort((a, b) => b - a)
console.log(cals[0] + cals[1] + cals[2])
