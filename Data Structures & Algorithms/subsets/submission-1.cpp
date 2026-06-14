class Solution {
private:
    void findSubsets(vector<int>& subset, vector<vector<int>>& subsets, int idx, const vector<int>& nums) {
        if (idx == nums.size()) {
            subsets.push_back(subset);
        }
        else {
            // dont include nums[idx]
            findSubsets(subset, subsets, idx + 1, nums);

            // include nums[idx]
            subset.push_back(nums[idx]);
            findSubsets(subset, subsets, idx + 1, nums);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        at every step, either choose to take a number or dont
        */

        vector<vector<int>> subsets;
        vector<int> subset;
        findSubsets(subset, subsets, 0, nums);
        return subsets;
    }
};
