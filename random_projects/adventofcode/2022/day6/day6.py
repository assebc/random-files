file = open("input.txt")
line = file.readline()

def ex1():
    total = 0
    array=[]
    sets = set()
    for c in range(len(line)):
        for i in range(4):
            array.append(line[c+i])
        for a in array:
            sets.add(a)
        if len(sets) == 4:
            total = c+4
            break
        else:
            sets.clear()
            array.clear()
            continue      

    print(total)

def ex2():
    total = 0
    array=[]
    sets = set()
    for c in range(len(line)):
        for i in range(14):
            array.append(line[c+i])
        
        for a in array:
            sets.add(a)
        
        if len(sets) == 14:
            total = c+14
            break
        else:
            sets.clear()
            array.clear()
            continue
    print(total)

ex1()
ex2()
