class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        neighbors = [[] for _ in range(n)]
        for i in range(n):
            xi, yi = points[i]
            for j in range(i + 1, n):
                xj, yj = points[j]
                dist = abs(xi - xj) + abs(yi - yj)
                neighbors[i].append((dist, j))
                neighbors[j].append((dist, i))
        
        cost = 0
        visited = [False] * n
        visited[0] = True
        heap = []
        for neighbor in neighbors[0]:
            heapq.heappush(heap, neighbor)
        while len(heap) > 0:
            edge_dist, edge_node = heapq.heappop(heap)
            if not visited[edge_node]:
                visited[edge_node] = True
                cost += edge_dist
                for neighbor in neighbors[edge_node]:
                    if not visited[neighbor[1]]:
                        heapq.heappush(heap, neighbor)
        
        return cost