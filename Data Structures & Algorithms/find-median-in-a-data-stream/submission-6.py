class MedianFinder:

    def __init__(self):
        self.size = 0
        self.array = []

    def addNum(self, num: int) -> None:
        self.size += 1
        self.array.append(num)

    def findMedian(self) -> float:
        self.array.sort()
        if self.size % 2 == 1:
            return self.array[self.size // 2]
        return (self.array[self.size // 2 - 1] + self.array[self.size // 2]) / 2