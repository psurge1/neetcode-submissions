class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        size_t nSz = nums.size();
        vector<unordered_map<int, int>> table(nSz + 1);
        table[0][0] = 1;
        for (int idx = 0; idx < nSz; ++idx) {
            for (auto [tempSum, count] : table[idx]) {
                table[idx + 1][tempSum + nums[idx]] += count;
                table[idx + 1][tempSum - nums[idx]] += count;
            }
        }
        return table[nSz][target];
    }
};
