class Solution {
private:
    void genCSums(vector<int>& currList, vector<vector<int>>& cSums, int idx, int target, const vector<int>& nums) {
        if (target == 0) {
            cSums.push_back(currList);
            return;
        }
        if (target < 0 || idx == nums.size()) {
            return;
        }
        
        genCSums(currList, cSums, idx + 1, target, nums);

        currList.push_back(nums[idx]);
        genCSums(currList, cSums, idx, target - nums[idx], nums);
        currList.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> cSums;
        vector<int> currList;
        genCSums(currList, cSums, 0, target, nums);

        return cSums;
    }
};
