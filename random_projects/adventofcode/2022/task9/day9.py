file = open("input.txt")
lines = file.readlines()

def move(d):
    move = {
        "U": (0, 1),
        "D": (0, -1),
        "R": (1, 0),
        "L": (-1, 0),
    }
    return move[d]

def move_tail(tail,head):
    difx = head[0] - tail[0]
    dify = head[1] - tail[1]
    if abs(difx) <= 1 and abs(dify) <=1: # radius of 1
        return (tail[0],tail[1])
    elif difx == 0:
        return (tail[0], tail[1] + dify // abs(dify)) 
    elif dify == 0:
        return (tail[0] + difx // abs(difx), tail[1])
    else:
        return (tail[0] + difx // abs(difx), tail[1] + dify // abs(dify))

def ex1():
    total = 0
    tail = head = (0,0)
    visited = set(tail) # start
    for line in lines:
        d,a = line.split(' ') # d = U, D, L, R and a = amount of moves in d direction
        a = int(a)
        for _ in range(a):
            mx, my = move(d)
            head = (head[0] + mx, head[1] + my)
            tail = move_tail(tail,head)
            visited.add(tail)

    total = len(visited)
    print(total)

def ex2():
    total = 0
    knots = [(0, 0) for _ in range(10)]
    visited = set()
    for line in lines:
        d,a = line.split(' ')
        a = int(a)
        for _ in range(a):
            mx, my = move(d)
            knots[0] = (knots[0][0] + mx, knots[0][1] + my)
            for k in range(1, len(knots)):
                knots[k] = move_tail(knots[k], knots[k - 1])
            visited.add(knots[-1])

    total = len(visited)
    print(total)

ex1()
ex2()