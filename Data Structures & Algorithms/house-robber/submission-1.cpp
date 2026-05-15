class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        // vector<int> maxMoney(n, 0);
        // maxMoney[n - 1] = nums[n - 1];
        nums[n - 2] = max(nums[n - 2], nums[n - 1]);

        for (int house = n - 3; house >= 0; --house) {
            nums[house] = max(nums[house] + nums[house + 2], nums[house + 1]);
        }

        return nums[0];
    }
};
