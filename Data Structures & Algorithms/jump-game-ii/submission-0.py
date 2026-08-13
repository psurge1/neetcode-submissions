class Solution:
    def jump(self, nums: List[int]) -> int:
        """
        Inputs:
        - array of jump lengths (all positive or zero)

        Output:
        - minimum number of jumps to reach the end

        Misc:
        - there is ALWAYS a valid answer

        Solutions:
        - BFS
            - For every index i, 
                spawn a search tree for every position i + 1 ... i + k, where k is the value of nums[i]
            - Shortest path = minimum search tree height
            - O(n!) time, O(1) space without memoization
            - O(n) time, O(n) space with memoization
        - Two pointers
            - keep track of a window of "reachable" cells for every iteration
            - the first iteration where the window contains the last element in nums 
                denotes the shortest path
            - O(n) time, O(1) space
        """

        low = 0
        high = 0
        n = len(nums)
        count = 0
        while high < n - 1:
            count += 1
            maxJump = low
            for idx in range(low, high + 1):
                maxJump = max(maxJump, idx + nums[idx])
            low = high + 1
            high = min(maxJump, n - 1)
        return count