import ast
import operator
from functools import cmp_to_key, reduce


def ex1():
    lines = parse_input()
    print(sum([ind for ind, line in enumerate(lines, 1) if cmp_values(*line) == 1])) 


def ex2():
    lines = parse_input()
    keys = [[[2]], [[6]]]
    flat_lines = keys + [item for sublist in lines for item in sublist]
    flat_lines.sort(key=cmp_to_key(cmp_values), reverse=True)
    print(reduce(operator.mul, [ind for ind, x in enumerate(flat_lines, 1) if x in keys])) 

def parse_input():
    with open("input.txt", "r", encoding="utf8") as f:
        return [[ast.literal_eval(line) for line in pair.strip().split("\n")] for pair in f.read().split("\n\n")]


# returns 1 if values are in the right order, -1 if not, 0 if equal
def cmp_values(left, right):
    match left, right:
        case int(), int():
            return (left < right) - (left > right)
        case list(), list():
            for cmp_val in map(cmp_values, left, right):
                if cmp_val:
                    return cmp_val
            return cmp_values(len(left), len(right))
        case int(), list():
            return cmp_values([left], right)
        case list(), int():
            return cmp_values(left, [right])
    raise ValueError(f"Invalid types: {type(left)} and {type(right)}")

ex1()
ex2()