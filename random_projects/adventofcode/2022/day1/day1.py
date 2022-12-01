file = open("input.txt")

amount = 0
atm = 0

for line in file.readlines():
    if str(line[0]) != '\n':
        atm += int(line)
    else:
        if amount < atm:
            amount = atm
        atm = 0

print(amount)
