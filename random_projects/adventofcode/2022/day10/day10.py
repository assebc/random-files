file = open("input.txt")
lines = file.readlines()

def cycle():
    x = 1
    cycles = 1
    register_values = {cycles: x}
    for line in lines:
        line = line.strip()
        match line.split(" "):
            case ["noop"]:
                cycles += 1
            case ["addx", val]:
                cycles += 2
                x += int(val)
        register_values[cycles] = x
    return register_values

    return cycle_strength

def get_register_value_at_cycle(register_values: dict[int, int], cycle: int) -> int:
    if cycle in register_values:
        return register_values[cycle]
    elif cycle - 1 in register_values:
        return register_values[cycle - 1]
    elif cycle - 2 in register_values:
        return register_values[cycle - 2]
    else:
        raise ValueError(f"Register value not found for {cycle=}")

def ex1():
    total = 0
    cycle_strength = cycle()
    
    for s in [20, 60, 100, 140, 180, 220]:
        total += s*get_register_value_at_cycle(cycle_strength,s)
    
    print(total)

def ex2():
    cycle_strength = cycle()
    drawn = []
    for position in range(240):
        _cycle = position + 1
        register_val = get_register_value_at_cycle(cycle_strength, _cycle)
        if -1 <= position % 40 - register_val <= 1:
            drawn.append(position)
    draw(drawn)


def draw(drawn: list[int]) -> None:
    for y in range(6):
        for x in range(40):
            if x + y * 40 in drawn:
                print("#", end="")
            else:
                print(".", end="")
        print()
    

ex1()
ex2()