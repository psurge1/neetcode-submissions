class Solution {
public:
    int maxArea(vector<int>& heights) {
        int leftIdx = 0;
        int rightIdx = heights.size() - 1;
        
        int maxArea = 0;
        while (leftIdx < rightIdx) {
            int leftHeight = heights[leftIdx];
            int rightHeight = heights[rightIdx];
            int area = (rightIdx - leftIdx) * min(leftHeight, rightHeight);
            maxArea = max(maxArea, area);
            if (leftHeight < rightHeight) {
                ++leftIdx;
            }
            else {
                --rightIdx;
            }
        }
        return maxArea;
    }
};
