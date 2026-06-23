class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            for (int j = i + 1; j < heights.size(); ++j) {
                int area = (j - i) * min(heights[i], heights[j]);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
