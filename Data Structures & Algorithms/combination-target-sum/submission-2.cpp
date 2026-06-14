class Solution {
private:
    void computeCombSums(vector<int>& addends, vector<vector<int>>& combSums, int idx, int target, const vector<int>& nums) {
        if (target == 0) {
            combSums.push_back(addends);
            return;
        }

        for (int jdx = idx; jdx < nums.size(); ++jdx) {
            if (nums[jdx] > target) {
                return;
            }

            addends.push_back(nums[jdx]);
            computeCombSums(addends, combSums, jdx, target - nums[jdx], nums);
            addends.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> addends;
        vector<vector<int>> combSums;
        computeCombSums(addends, combSums, 0, target, nums);
        return combSums;
    }
};
