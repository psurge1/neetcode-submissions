class MedianFinder:

    def __init__(self):
        self.size = 0
        self.array = []

    def addNum(self, num: int) -> None:
        idx = 0
        while idx < self.size and self.array[idx] < num:
            idx += 1
        self.array = self.array[:idx] + [num] + self.array[idx:]
        self.size += 1


    def findMedian(self) -> float:
        if self.size % 2 == 1:
            return self.array[self.size // 2]
        return (self.array[self.size // 2 - 1] + self.array[self.size // 2]) / 2