class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        """
        assume we start at some index i, and track the amount of gallons in our tank
        we can travel with index j from i till n, adding the diff of [j] to the tank
        if the tank is ever negative, we know that starting from any index from i to j will yield a negative tank result, meaning it is impossible to travel from i to the first index where tank is negative
        - this is because if we start from an index i - 1, then the total gas in the tank at index j must be greater than or equal to the total gas if we start from index i. This s because we only move j forward while the tank is net positive, so any carryover gas can be contributed from starting earlier.

        Using this observation, we can compute a running tank value, and if the tank value ever drops below 0, we restart at the next index. The first starting index with a non-negative running sum that reaches the end of the array is our index.

        We must also keep in mind that enough gas must exist in the stations to cover the total distance. This is why sum(gas) >= sum(cost) for a path to exist.
        """
        if sum(gas) < sum(cost):
            return -1
        
        running_sum = 0
        start_idx = 0
        idx = start_idx
        while idx < len(gas):
            running_sum += gas[idx] - cost[idx]
            if running_sum < 0:
                start_idx = idx + 1
                idx = start_idx
                running_sum = 0
            else:
                idx += 1
        if start_idx == len(gas):
            return -1
        return start_idx