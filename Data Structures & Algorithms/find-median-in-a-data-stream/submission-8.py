class MedianFinder:

    def __init__(self):
        # O(1)
        self.upper_half = [] # min heap
        self.lower_half = [] # max heap

    def addNum(self, num: int) -> None:
        # O(logN)
        """
        Given: num (integer to add), upper_half and its size, lower_half and its size
        upper_half should contain the largest n/2 numbers
        lower_half should contain the smallest n/2 numbers

        if size of upper_half equals size of lower_half, just add the number to upper_half
        if size of upper_half < size of lower_half:
            compare num against the root of upper_half
            if num is greater than the root, just add it to the min heap
            if num is less than the root, insert it into lower half, pop the largest element from lower half and insert it into upper half
        else: vise versa
        """
        upper_size = len(self.upper_half)
        lower_size = len(self.lower_half)
        total_size = upper_size + lower_size
        if total_size == 0:
            heapq.heappush(self.upper_half, num)
        else:
            """
            criteria:
            - upperhalf >= lowerhalf (in size)
            - min(upperhalf) >= max(lowerhalf)

            insertion cases:
            - num <= min(upperhalf)
                insert into lowerhalf
            - num >= max(lowerhalf)
                insert into upperhalf
            
            rebalance cases:
            - size(upperhalf) = size(lowerhalf) + 2:
                pop from upperhalf, add to lower half
            - size(lowerhalf) > size(upperhalf):
                pop from lowerhalf, add to upper half
            """
            if num < self.upper_half[0]:
                heapq.heappush(self.lower_half, -num)
            else:
                heapq.heappush(self.upper_half, num)
            
            if len(self.upper_half) == len(self.lower_half) + 2:
                upper_min = heapq.heappop(self.upper_half)
                heapq.heappush(self.lower_half, -upper_min)
            if len(self.lower_half) > len(self.upper_half):
                lower_max = -heapq.heappop(self.lower_half)
                heapq.heappush(self.upper_half, lower_max)

    def findMedian(self) -> float:
        # O(1)
        upper_half_size = len(self.upper_half)
        lower_half_size = len(self.lower_half)
        if (upper_half_size + lower_half_size) % 2 == 0:
            return (self.upper_half[0] - self.lower_half[0]) / 2
        return self.upper_half[0]