class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [-stone for stone in stones]
        heapq.heapify(heap)
        while len(heap) > 1:
            one = heapq.heappop(heap)
            two = heapq.heappop(heap)
            result = -abs(one - two)
            if result != 0:
                heapq.heappush(heap, result)
        if len(heap) == 1:
            return -heap[0]
        return 0