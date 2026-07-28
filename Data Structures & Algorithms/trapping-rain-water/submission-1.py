class Solution:
    def trap(self, height: List[int]) -> int:
        maxHeightFromRight = [0] * len(height)
        for col in range(len(height) - 2, -1, -1):
            maxHeightFromRight[col] = max(maxHeightFromRight[col + 1], height[col + 1])
        

        water = 0
        maxHeightFromLeft = height[0]
        for col in range(1, len(height)):
            water += max(0, min(maxHeightFromLeft, maxHeightFromRight[col]) - height[col])
            maxHeightFromLeft = max(maxHeightFromLeft, height[col])
        
        return water