class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        int prev = nums[n - 1];
        int curr = max(nums[n - 2], prev);

        for (int house = n - 3; house >= 0; --house) {
            int temp = curr;
            curr = max(nums[house] + prev, curr);
            prev = temp;
        }

        return curr;
    }
};
