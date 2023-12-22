lines = []
require("fs")
  .readFileSync("input.txt").toString()
  .split(/\r?\n/)
  .forEach( (line) => {
    lines.push(line)
  }
);

function traduce(c) {
  if(c == "A") return "X"
  if(c == "B") return "Y"
  return "Z"
}

function toPoint(c) {
  if(c == "X") return 1
  if(c == "Y") return 2
  return 3
}

function win(a, b) {
  if(a == "X" && b == "Y") return 1
  if(a == "Y" && b == "Z") return 1
  if(a == "Z" && b == "X") return 1
  return 0
}

let total_score = 0
lines.map((line) => {
  line = line.split(" ")
  if(traduce(line[0]) === line[1]) {
    total_score += 3 + toPoint(line[1])
  } else if(win(traduce(line[0]), line[1]) === 1) {
    total_score += 6 + toPoint(line[1]) 
  } else {
    total_score += 0 + toPoint(line[1])
  }
})

console.log(total_score)
