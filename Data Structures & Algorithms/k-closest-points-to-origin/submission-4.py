class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        """
        remember the function signature for heappush and heappop (MUST INCLUDE HEAP AS AN ARGUMENT TO BOTH)
        remember that heaps in python are minheaps by default
        this question requires us to keep the k smallest elements in the heap, thus, we must pop all of the largest elements
        - that means that a max heap is ideal for this scenario (pop from a max heap removes the largest element, the smallest elements remain in the heap)
        """
        heap = []
        for point in points:
            heapq.heappush(heap, (-math.sqrt(point[0]**2 + point[1]**2), point[0], point[1]))
            if len(heap) > k:
                heapq.heappop(heap)
        return [[point[1], point[2]] for point in heap]