## Dijkstra's Algorithm - Single Source Shortest Path

n = no. of nodes, m = no. of edges

for directed graph we add only edge (u, v) : u->v
for undirected graph add another edge (v, u): v->u
for weighted graph we have added w weight to each edge

s = Source from which distance is measured

dist contains distance of all nodes from source s

INF = 1B, to avoid overflow	
