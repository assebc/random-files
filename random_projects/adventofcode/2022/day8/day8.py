import numpy as np

file = open("input.txt")
lines = file.read().strip().split()
grid = [list(map(int, list(line))) for line in lines]
n = len(grid)
m = len(grid[0])
grid2 = np.array(grid)

def ex1():

    total = 0
    for i in range(n):
        for j in range(m):
            h = grid2[i, j]

            if j == 0 or np.amax(grid2[i, :j]) < h:
                total += 1
            elif j == m - 1 or np.amax(grid2[i, (j+1):]) < h:
                total += 1
            elif i == 0 or np.amax(grid2[:i, j]) < h:
                total += 1
            elif i == n - 1 or np.amax(grid2[(i+1):, j]) < h:
                total += 1

    print(total)

def ex2():
    total = 0
    dd = [[0, 1], [0, -1], [1, 0], [-1, 0]]

    for i in range(n):
        for j in range(m):
            h = grid2[i, j]
            score = 1

            # Scan in 4 directions
            for di, dj in dd:
                ii, jj = i + di, j + dj
                dist = 0

                while (0 <= ii < n and 0 <= jj < m) and grid2[ii, jj] < h:
                    dist += 1
                    ii += di
                    jj += dj

                    if (0 <= ii < n and 0 <= jj < m) and grid2[ii, jj] >= h:
                        dist += 1

                score *= dist

            total = max(total, score)
    print(total)

ex1()
ex2()