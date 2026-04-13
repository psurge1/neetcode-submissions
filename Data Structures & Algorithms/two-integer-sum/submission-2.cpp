class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> targets;
        for (int i = 0; i < n; ++i) {
            if (targets.find(nums[i]) != targets.end()) {
                return vector<int>{targets[nums[i]], i};
            }
            targets[target - nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};
