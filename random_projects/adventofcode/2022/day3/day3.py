file = open("input.txt")
lines = file.readlines()

def get_num(char):
    char = str(char)
    if 'a'<=char<='z':
        return ord(char)-ord('a')+1
    return ord(char)-ord('A') + 27
    
def ex1():
    total = 0
    for line in lines:
        line = line.strip()
        c1, c2 = line[:len(line)//2], line[len(line)//2:]
        for j in c1:
            if j in c2:
                total += get_num(j)
                break
        
    print(total)

def ex2():
    total = 0
    i = 0
    while i < len(lines): 
        for j in lines[i]:
            if j in lines[i+1] and j in lines[i+2]:
                total += get_num(j)
                break
            
        i+=3

    print(total)

ex1()
ex2()