class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        """
        REMEMBER that the only property of a heap is that the element at the root (or sub root) is the smallest/largest amongst all elements in the heap/subheap
        nothing can be said about the ordering of elements in the rest of the heap
        """
        heap = []
        def dist(point):
            return math.sqrt(point[0]**2 + point[1]**2)
        dist_points = [(dist(point), point[0], point[1]) for point in points]
        heapq.heapify(dist_points)
        result = []
        for _ in range(k):
            dist_point = heapq.heappop(dist_points)
            result.append([dist_point[1], dist_point[2]])
        return result