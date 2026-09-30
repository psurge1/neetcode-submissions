class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        min_dists = [-1] * n
        min_dists[0] = 0
        in_mst = [False] * n

        cost = 0
        for _ in range(n):
            min_node = -1
            for node in range(n):
                if in_mst[node]:
                    continue
                if min_node == -1:
                    min_node = node
                elif min_dists[node] != -1 and min_dists[node] < min_dists[min_node]:
                    min_node = node
            cost += min_dists[min_node]
            in_mst[min_node] = True
            for node in range(n):
                if node == min_node or in_mst[node]:
                    continue
                xmin, ymin = points[min_node]
                xnode, ynode = points[node]
                dist = abs(xmin - xnode) + abs(ymin - ynode)
                if min_dists[node] == -1:
                    min_dists[node] = dist
                min_dists[node] = min(min_dists[node], dist)

        return cost