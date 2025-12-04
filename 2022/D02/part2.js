lines = []
require("fs")
  .readFileSync("input.txt").toString()
  .split(/\r?\n/)
  .forEach( (line) => {
    lines.push(line)
  }
);

function toPoint(c) {
  if(c == "A") return 1
  if(c == "B") return 2
  return 3
}

function win(a, b) {
  if(a == "A" && b == "B") return 1
  if(a == "B" && b == "C") return 1
  if(a == "C" && b == "A") return 1
  return 0
}

function toWin(a) {
  if(a == "A") return "B"
  if(a == "B") return "C"
  if(a == "C") return "A"
}

function toDraw(a) {
  return a
}
 
function toLose(a) {
  if(a == "A") return "C"
  if(a == "B") return "A"
  if(a == "C") return "B"
}

function giveOption(a, b) {
  if(b == "X") return toLose(a)
  if(b == "Y") return toDraw(a)
  return toWin(a)
}

let total_score = 0
lines.map((line) => {
  line = line.split(" ")
  line[1] = giveOption(line[0], line[1])
  if(line[0] === line[1]) {
    total_score += 3 + toPoint(line[1])
  } else if(win(line[0], line[1]) === 1) {
    total_score += 6 + toPoint(line[1]) 
  } else {
    total_score += 0 + toPoint(line[1])
  }
})

console.log(total_score)
