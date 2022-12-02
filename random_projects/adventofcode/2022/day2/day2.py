file = open("input.txt")

rock = {}
rock['A'] = 1
rock['X'] = 1

paper = {}
paper['B'] = 2
paper['Y'] = 2

scissors = {}
scissors['C'] = 3
scissors['Z'] = 3

win = 6
loss = 0
draw = 3

def winner(line):
    total = 0
    line = str(line)
    splited = line.split(' ')
    splited[1] = splited[1].strip()

    if splited[0] in rock:
        if splited[1] in rock:
            total = draw + rock[splited[1]]
        elif splited[1] in paper:
            total = win + paper[splited[1]]
        elif splited[1] in scissors:
            total = loss + scissors[splited[1]]

    elif splited[0] in paper:
        if splited[1] in rock:
            total = loss + rock[splited[1]]
        elif splited[1] in paper:
            total = draw + paper[splited[1]]
        elif splited[1] in scissors:
            total = win + scissors[splited[1]]
    elif splited[0] in scissors:
        if splited[1] in rock:
            total = win + rock[splited[1]]
        elif splited[1] in paper:
            total = loss + paper[splited[1]]
        elif splited[1] in scissors:
            total = draw + scissors[splited[1]]

    return total

totals = 0

for line in file.readlines():
    totals += winner(line)

print(totals)
    
        


