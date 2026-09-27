class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [0] * target
        for pos, sp in zip(position, speed):
            cars[pos] = (target - pos) / sp
        
        fleets = 0
        prev_arrival_time = 0
        for pos in range(target - 1, -1, -1):
            if cars[pos] > prev_arrival_time:
                fleets += 1
                prev_arrival_time = cars[pos]

        return fleets