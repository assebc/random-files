file = open("input.txt")
lines = file.readlines()

def ex1():
    total = 0
    for line in lines:
        line = line.strip()
        a,b = line.split(',')
        a1,a2 = a.split('-')
        b1,b2 = b.split('-')
        asd = set()
        bsd = set()
        for i in range(int(a1),int(a2)+1):
            asd.add(i)
        for i in range (int(b1),int(b2)+1):
            bsd.add(i)
        
        if int(a1) in bsd and int(a2) in bsd:
            total +=1
        elif int(b1) in asd and int(b2) in asd:
            total+=1

    print(total)


def ex2():
    total = 0
    for line in lines:
        line = line.strip()
        a,b = line.split(',')
        a1,a2 = a.split('-')
        b1,b2 = b.split('-')
        asd = set()
        bsd = set()
        for i in range(int(a1),int(a2)+1):
            asd.add(i)
        for i in range (int(b1),int(b2)+1):
            bsd.add(i)
        
        if int(a1) in bsd or int(a2) in bsd:
            total +=1
        elif int(b1) in asd or int(b2) in asd:
            total+=1

    print(total)

ex1()
ex2()