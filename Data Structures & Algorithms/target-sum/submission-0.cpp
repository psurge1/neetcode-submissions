class Solution {
private:
    int findWays(int target, int idx, const vector<int>& nums) {
        if (idx == nums.size()) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }

        return findWays(target - nums[idx], idx + 1, nums) + findWays(target + nums[idx], idx + 1, nums);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return findWays(target, 0, nums);
    }
};
