class DSU:
    def __init__(self, n):
        self.parents = [i for i in range(n)]
        self.rank = [0] * n
    
    def findRoot(self, node):
        if self.parents[node] != node:
            self.parents[node] = self.findRoot(self.parents[node])
        return self.parents[node]
    
    def connected(self, nodeA, nodeB):
        rootA = self.findRoot(nodeA)
        rootB = self.findRoot(nodeB)
        if rootA == rootB:
            return True

        if self.rank[rootA] > self.rank[rootB]:
            self.parents[rootB] = rootA
        elif self.rank[rootB] > self.rank[rootA]:
            self.parents[rootA] = rootB
        else:
            self.parents[rootA] = rootB
            self.rank[rootB] += 1
        return False

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        edges = []
        for i in range(n):
            xi, yi = points[i]
            for j in range(i + 1, n):
                xj, yj = points[j]
                dist = abs(xi - xj) + abs(yi - yj)
                edges.append((dist, i, j))
        edges.sort()

        graph = DSU(n)
        cost = 0
        for edge in edges:
            if not graph.connected(edge[1], edge[2]):
                cost += edge[0]
        return cost