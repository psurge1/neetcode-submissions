class Solution {
private:
    void generateSubsets(int idx, vector<int>& subset, vector<vector<int>>& subsets, const vector<int>& nums) {
        if (idx == nums.size()) {
            subsets.push_back(subset);
        }
        else {
            subset.push_back(nums[idx]);
            generateSubsets(idx + 1, subset, subsets, nums);
            subset.pop_back();

            int skipVal = nums[idx];
            while (idx < nums.size() && nums[idx] == skipVal) {
                ++idx;
            }
            generateSubsets(idx, subset, subsets, nums);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        generateSubsets(0, subset, subsets, nums);
        return subsets;
    }
};