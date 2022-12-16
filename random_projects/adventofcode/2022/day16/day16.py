import argparse
import collections
import itertools
import os.path
import re

RATE = re.compile(r'rate=(\d+);')
VALVES = re.compile(r'to valves? (.*)$')

file = open("input.txt")
lines = file.readlines()

def ex1():
    edges = {}
    rates = {}

    for line in lines:
        _, name, *_ = line.split()
        match_valves = VALVES.search(line)
        assert match_valves is not None
        targets = match_valves[1].split(', ')
        match = RATE.search(line)
        assert match is not None
        edges[name] = targets
        rates[name] = int(match[1])

    weights = {}
    positive_rates = frozenset(k for k, v in rates.items() if v)
    meaningful_edges = ['AA', *positive_rates]
    for a, b in itertools.combinations(meaningful_edges, r=2):
        todo_bfs: collections.deque[tuple[str, ...]]
        todo_bfs = collections.deque([(a,)])
        while todo_bfs:
            path = todo_bfs.popleft()
            if path[-1] == b:
                break
            else:
                todo_bfs.extend((*path, n) for n in edges[path[-1]])
        weights[(a, b)] = len(path)
        weights[(b, a)] = len(path)

    # time to total
    best = -1
    todo: list[tuple[int, int, tuple[str, ...], frozenset[str]]]
    todo = [(0, 0, ('AA',), positive_rates)]
    while todo:
        score, time, route, possible = todo.pop()
        best = max(best, score)

        for p in possible:
            needed_time = time + weights[(route[-1], p)]
            if needed_time < 30:
                todo.append((
                    score + (30 - needed_time) * rates[p],
                    needed_time,
                    route + (p,),
                    possible - {p},
                ))

    print(best) 

def ex2():
    edges = {}
    rates = {}

    for line in lines:
        _, name, *_ = line.split()
        match_valves = VALVES.search(line)
        assert match_valves is not None
        targets = match_valves[1].split(', ')
        match = RATE.search(line)
        assert match is not None
        edges[name] = targets
        rates[name] = int(match[1])

    weights = {}
    positive_rates = frozenset(k for k, v in rates.items() if v)
    meaningful_edges = ['AA', *positive_rates]
    for a, b in itertools.combinations(meaningful_edges, r=2):
        todo_bfs: collections.deque[tuple[str, ...]]
        todo_bfs = collections.deque([(a,)])
        while todo_bfs:
            path = todo_bfs.popleft()
            if path[-1] == b:
                break
            else:
                todo_bfs.extend((*path, n) for n in edges[path[-1]])
        weights[(a, b)] = len(path)
        weights[(b, a)] = len(path)

    # time to total
    best: dict[frozenset[str], int] = {}
    todo: list[tuple[int, int, tuple[str, ...], frozenset[str]]]
    todo = [(0, 0, ('AA',), positive_rates)]
    while todo:
        score, time, route, possible = todo.pop()

        route_k = frozenset(route) - {'AA'}
        best_val = best.setdefault(route_k, score)
        best[route_k] = max(best_val, score)

        for p in possible:
            needed_time = time + weights[(route[-1], p)]
            if needed_time < 26:
                todo.append((
                    score + (26 - needed_time) * rates[p],
                    needed_time,
                    route + (p,),
                    possible - {p},
                ))

    print(max(best[k1] + best[k2] for k1, k2 in itertools.combinations(best, r=2) if not k1 & k2)) 
    

ex1()
ex2()
