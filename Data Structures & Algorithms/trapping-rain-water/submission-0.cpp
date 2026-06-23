class Solution {
public:
    int trap(vector<int>& height) {
        int width = height.size();
        vector<int> maxHeightFromLeft(width, 0);
        for (int col = 1; col < width; ++col) {
            maxHeightFromLeft[col] = max(maxHeightFromLeft[col - 1], height[col - 1]);
        }

        int water = 0;
        int maxHeightFromRight = height[width - 1];
        for (int col = width - 2; col >= 0; --col) {
            water += max(0, min(maxHeightFromLeft[col], maxHeightFromRight) - height[col]);
            maxHeightFromRight = max(maxHeightFromRight, height[col]);
        }
        return water;
    }
};
