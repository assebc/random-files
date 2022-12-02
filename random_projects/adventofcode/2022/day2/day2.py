file = open("input.txt")

rock = {}
rock['A'] = 1

paper = {}
paper['B'] = 2

scissors = {}
scissors['C'] = 3

win = 6
loss = 0
draw = 3

def points(line):
    total = 0
    line = str(line)
    splited = line.split(' ')
    splited[1] = splited[1].strip()

    if splited[0] in rock:
        if splited[1] == 'X':
            total = draw + 1
        elif splited[1] == 'Y':
            total = win + 2
        elif splited[1] == 'Z':
            total = loss + 3

    elif splited[0] in paper:
        if splited[1] == 'X':
            total = loss + 1
        elif splited[1] == 'Y':
            total = draw + 2
        elif splited[1] == 'Z':
            total = win + 3
    elif splited[0] in scissors:
        if splited[1] == 'X':
            total = win + 1
        elif splited[1] == 'Y':
            total = loss + 2
        elif splited[1] == 'Z':
            total = draw + 3

    return total

def find(line,cond):
    points = 0
    line = str(line)
    cond = str(cond)
    if line == 'A':
        if cond == "loss":
            points = 3 + loss
        elif cond == "win":
            points = 2 + win
        elif cond == "draw":
            points = 1 + draw

    elif line == 'B':
        if cond == "loss":
            points = 1 + loss
        elif cond == "win":
            points = 3 + win
        elif cond == "draw":
            points = 2 + draw

    elif line == 'C':
        if cond == "loss":
            points = 2 + loss
        elif cond == "win":
            points = 1 + win
        elif cond == "draw":
            points = 3 + draw

    return points

def points2(line):
    total = 0
    line = str(line)
    splited = line.split(' ')
    splited[1] = splited[1].strip()

    if splited[1] == 'X': # loss
        total += find(splited[0],"loss")
    elif splited[1] == 'Y': # draw
        total += find(splited[0],"draw")
    elif splited[1] == 'Z': # win
        total += find(splited[0],"win")

    return total


totals = 0

for line in file.readlines():
    totals += points2(line)

print(totals)
    
        


