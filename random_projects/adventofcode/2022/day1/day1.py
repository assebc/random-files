file = open("input.txt")

atm = 0
top_3 = [0,0,0]

def get_min(top_3=[]):
    minas = top_3[0]
    if minas <= top_3[1] and minas <= top_3[2]:
        return (minas,0)
    elif minas <= top_3[1]:
        return (top_3[2],2)
    elif minas>= top_3[1] and top_3[1]>= top_3[2]:
        return (top_3[2],2)
    else:
        return (top_3[1],1)

for line in file.readlines():
    if str(line[0]) != '\n':
        atm += int(line)
    else:
        (mina,pos) = get_min(top_3)
        if atm > mina:
            top_3[pos] = atm
        atm = 0

amount = 0
for i in top_3:
    amount += i
print(top_3)
print(amount)


        
