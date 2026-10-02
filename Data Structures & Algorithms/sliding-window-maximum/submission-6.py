class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # Heap or Monotonic Stack
        """
        Biggest Mistakes:
        - Syntax
            - forgetting to include heap as an argument to heappush/heappop
        - Edge Cases
            - first window
                - deciding to add the max of the first k elements inside the loop or before the loop
            - last window
                - off by one error
        """
        max_elements = []
        heap = []
        right = 0
        while right < k:
            heapq.heappush(heap, (-nums[right], right))
            right += 1
        
        left = 0
        while right <= len(nums):
            max_elements.append(-heap[0][0])
            if right < len(nums):
                heapq.heappush(heap, (-nums[right], right))
            right += 1
            left += 1
            while len(heap) > 0 and heap[0][1] < left:
                heapq.heappop(heap)
        return max_elements