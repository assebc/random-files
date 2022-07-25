def mst_Prim(g):
	fringe = {}
	status = {}
	for i in g:
		status[i] = 'UNSEEN'
	edgeCount = 0

	x = 0;
	status[x] = 'INTREE'
	parent[x] = -1

	while (edgeCount < len(g)-1):
		for y in g[x]:
			wxy = g[x][y] # weight of edge (x,y)
			if status[y] == 'UNSEEN':
				# add y to fringe with candidate edge (x,y)
				status[y] = 'FRINGE'
				parent[y] = x
				fringe[y] = wxy # dictionary insertion
			elif status[y] == 'FRINGE' and wxy < fringe[y]:
				# replace candidate edge of y by (x,y)
					parent[y] = x
					fringe[y] = wxy # dictionary update

		# are we blocked? (non-connected graph)
		if len(fringe) == 0:
			return False

		# select next candidate edge and vertex;
		# remove them from fringe and add to tree
		x = min(fringe, key=lambda x:fringe[x])
		del fringe[x]
		status[x] = 'INTREE'
		edgeCount += 1
		
	return True

graph = {
	0: { 1: 2, 5: 7, 6: 3 },
	1: { 0: 2, 2: 4, 6: 6 },
	2: { 1: 4, 3: 2, 7: 2 },
	3: { 2: 2, 4: 1, 7: 8 },
	4: { 3: 1, 5: 6, 8: 2 },
	5: { 0: 7, 4: 6, 8: 5 },
	6: { 0: 3, 1: 6, 7: 3, 8:1 },
	7: { 2: 2, 3: 8, 6: 3, 8:4 },
	8: { 4: 2, 5: 5, 6: 1, 7:4 }
}

def printGraph(g):
	for i in g:
	print"[%s]"%(i),

	for j in sorted(g[i].keys()):
		print "-> (%s, %s)"%(j,g[i][j]),
	print

printGraph(graph)
print

parent = {}
ok = mst_Prim(graph)
if ok:
	sum = 0;
	print "\nMST:\n",
	for i in graph:
		if parent[i]>=0 :
			print"%1s--%1s"%(parent[i], i)
			sum += graph[i][parent[i]]
	print "Total weight = ", sum
else:
	print "UNCONECTED GRAPH, CANNOT BUILD MST!"
