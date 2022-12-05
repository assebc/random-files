file = open("input.txt")
lines = file.readlines()

def populate():
    stacks = {}
    stacks[0] = ['G','T','R','W']
    stacks[1] = ['G','C','H','P','M','S','V','W']
    stacks[2] = ['C','L','T','S','G','M']
    stacks[3] = ['J','H','D','M','W','R','F']
    stacks[4] = ['P','Q','L','H','S','W','F','J']
    stacks[5] = ['P','J','D','N','F','M','S']
    stacks[6] = ['Z','B','D','F','G','C','S','J']
    stacks[7] = ['R','T','B']
    stacks[8] = ['H','N','W','L','C']
    return stacks

stacks = populate()
stacks2 = populate()
def ex1():
    res = ""
    for line in lines:
        if line[:4] == "move":
            line = line.strip()
            splited = line.split(' ')
            splited.remove('move')
            splited.remove('from')
            splited.remove('to')
            _from = [int]
            _to = [int]
            _from = stacks[int(splited[1])-1]
            _to = stacks[int(splited[2])-1]
            _amount = int(splited[0])
            for i in range(_amount):
                _to.append(_from.pop())
                stacks[int(splited[1])-1] = _from
                stacks[int(splited[2])-1] = _to
    
    for i in stacks.keys():
        res = res + stacks[i].pop()

    print(res)

def ex2():
    res = ""
    for line in lines:
        if line[:4] == "move":
            line = line.strip()
            splited = line.split(' ')
            splited.remove('move')
            splited.remove('from')
            splited.remove('to')
            _from = [int]
            _to = [int]
            _from = stacks2[int(splited[1])-1]
            _to = stacks2[int(splited[2])-1]
            _amount = int(splited[0])
            if _amount == 1:
                _to.append(_from.pop())
                stacks2[int(splited[1])-1] = _from
                stacks2[int(splited[2])-1] = _to
            else:
                aux = []
                for i in range(_amount):
                    aux.append(_from.pop())

                aux.reverse()
                for let in aux:
                    _to.append(let)
                stacks2[int(splited[1])-1] = _from
                stacks2[int(splited[2])-1] = _to
                

    for i in stacks.keys():
        res = res + stacks2[i].pop()

    print(res)

ex1()
ex2()