class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> maxMoney(n, 0);
        maxMoney[n - 1] = nums[n - 1];
        maxMoney[n - 2] = max(nums[n - 2], maxMoney[n - 1]);

        for (int house = n - 3; house >= 0; --house) {
            maxMoney[house] = max(nums[house] + maxMoney[house + 2], maxMoney[house + 1]);
        }

        return maxMoney[0];
    }
};
