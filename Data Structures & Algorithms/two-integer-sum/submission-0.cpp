class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0, n = nums.size(); i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{-1, -1};
    }
};
