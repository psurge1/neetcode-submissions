class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> targets;
        for (int i = 0; i < n; ++i) {
            targets[target - nums[i]] = i;
        }
        for (int j = 0; j < n; ++j) {
            if (targets.find(nums[j]) != targets.end() && j != targets[nums[j]]) {
                return vector<int>{j, targets[nums[j]]};
            }
        }
        return vector<int>{-1, -1};
    }
};
