class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        """
        cars are arranged in a linear fashion, with varying speeds
        position is not a sorted
        a fleet is a group of cars driving at the same position/speed
        a faster car that catches up to the car in front of it joins it (lowers its speed to match the car in front)

        arrival time = remaining_dist / speed
        """

        n = len(position)
        cars = [(position[i], speed[i]) for i in range(n)]
        cars.sort()
        fleets = 0
        prev_arrival_time = 0
        for idx in range(n - 1, -1, -1):
            arrival_time = (target - cars[idx][0]) / cars[idx][1]
            if arrival_time > prev_arrival_time:
                fleets += 1
                prev_arrival_time = arrival_time
        return fleets