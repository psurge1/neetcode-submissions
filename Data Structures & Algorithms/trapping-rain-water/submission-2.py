class Solution:
    def trap(self, height: List[int]) -> int:
        max_left = 0
        max_right = 0
        l = 0
        r = len(height) - 1
        water = 0
        while l < r:
            if height[l] < height[r]:
                water += max(0, max_left - height[l])
                max_left = max(max_left, height[l])
                l += 1
            else:
                water += max(0, max_right - height[r])
                max_right = max(max_right, height[r])
                r -= 1
        return water