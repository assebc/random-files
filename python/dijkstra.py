def sp_Dijkstra(g, s):
	fringe = {}
	status = {}

	## NEW IN DIJKSTRA
	dist = {}
	for i in g:
		status[i] = 'UNSEEN'

	edgeCount = 0
	x = s;

	status[x] = 'INTREE'
	parent[x] = -1

	## NEW IN DIJKSTRA
	dist[x] = 0
	while (edgeCount < len(g)-1):
		for y in g[x]:
			wxy = g[x][y]
			if status[y] == 'UNSEEN':
				# add y to fringe with candidate edge (x,y)
				status[y] = 'FRINGE'
				parent[y] = x
				fringe[y] = wxy
				## NEW IN DIJKSTRA
				dist[y] = dist[x] + wxy

			## MODIFIED FOR DIJKSTRA
			elif (status[y] == 'FRINGE'
			and dist[x] + wxy < dist[y]):
				# replace candidate edge of y by (x,y)
				parent[y] = x
				fringe[y] = wxy
				## NEW IN DIJKSTRA ##
				dist[y] = dist[x] + wxy

		# are we blocked? (non-connected graph)
		if len(fringe) == 0:
			return False

		# select next candidate edge and vertex

		# remove them from fringe and add to tree
		## MODIFIED FOR DIJKSTRA
		x = min(fringe, key=lambda x:dist[x])
		del fringe[x]
		status[x] = 'INTREE'
		edgeCount += 1

	return True

graph = {
	0: { 1: 2, 5: 9, 6: 5 },
	1: { 2: 4, 6: 6 },
	2: { 3: 2, 7: 5 },
	3: { 4: 1, 7: 1 },
	4: { },
	5: { 4: 6 },
	6: { 7: 5, 8: 2 },
	7: { },
	8: { 4: 3, 5: 1 }
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
ok = sp_Dijkstra(graph, 0)
if ok:
	sum = 0;
	print "\nShortest Paths Tree:\n",
	for i in graph:
		if parent[i]>=0 :
			print"%1s--%1s"%(parent[i], i)
else:
	print "UNCONECTED GRAPH, CANNOT REACH ALL VERTICES!"
