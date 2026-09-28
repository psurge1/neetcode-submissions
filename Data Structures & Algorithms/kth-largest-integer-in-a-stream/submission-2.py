class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.heap = []
        self.k = k
        
        i = 0
        while i < len(nums) and i < self.k:
            heapq.heappush(self.heap, nums[i])
            i += 1
        
        while i < len(nums):
            if nums[i] > self.heap[0]:
                heapq.heappop(self.heap)
                heapq.heappush(self.heap, nums[i])
            i += 1

    def add(self, val: int) -> int:
        if len(self.heap) == 0:
            self.heap.append(val)
        elif val > self.heap[0]:
            if len(self.heap) == self.k:
                heapq.heappop(self.heap)
            heapq.heappush(self.heap, val)
        return self.heap[0]
