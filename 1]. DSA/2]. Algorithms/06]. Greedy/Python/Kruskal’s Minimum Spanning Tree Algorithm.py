# Python program for Kruskal's algorithm to find
# Minimum Spanning tree
# undirected and weighted graph
# Kruskal's algorithm finds a minimum spanning forest of an undirected edge-weighted graph. 
# If the graph is connected, it finds a minimum spanning tree. 
# It is a greedy algorithm in graph theory as in each step it adds the next lowest-weight edge 
 

# class 
class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [1 for _ in range(n)]
    
    # make a and b part of the same component
    # union by rank optimization
    def union(self, a, b):
        pa = self.find(a)
        pb = self.find(b)
        if pa == pb: return
        if self.rank[pa] > self.rank[pb]:
            self.parent[pb] = pa
            self.rank[pa] += self.rank[pb]
        else:
            self.parent[pa] = pb
            self.rank[pb] += self.rank[pa]
    
    # find the representative of the 
    # path compression optimization
    def find(self, a):
        if self.parent[a] == a:
            return a
        
        self.parent[a] = self.find(self.parent[a])
        return self.parent[a]
    

class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        
        n = len(points)
        edges = []
        for i in range(n):
            for j in range(i+1, n):
                dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                edges.append((dist, i, j))
        
        # sort based on cost (i.e. distance)
        edges.sort()
        
        # using Kruskal's algorithm to find the cost of Minimum Spanning Tree
        res = 0
        ds = DisjointSet(n)
        for cost, u, v in edges:
            if ds.find(u) != ds.find(v):
                ds.union(u, v)
                res += cost
        
        return res

# With union by rank - O(log N)  (Time Complexity)