class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        if we want to contain the kth largest elements in a min heap, we MUST ONLY pop from the heap if the size of the heap is GREATER than k (NOT IF IT IS EQUAL TO k)
        to track the k largest elements, use a min heap of size k
        to track the k smallest elements, use a max heap of size k
        - this is because the first element to leave a max heap will be the largest of the k in the heap, so the k - 1 elements left in the heap will guaranteed be smaller. this is true in the oppposite case as well.
        """
        heap = []
        for num in nums:
            heapq.heappush(heap, num)
            if len(heap) > k:
                heapq.heappop(heap)
        return heap[0]