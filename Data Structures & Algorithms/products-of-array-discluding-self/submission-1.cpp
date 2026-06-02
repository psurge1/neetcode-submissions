class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int runningProductFromLeft = 1;
        vector<int> productFromRight(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            productFromRight[i] = productFromRight[i + 1] * nums[i + 1];
        }

        vector<int> products(n);
        for (int i = 0; i < n; ++i) {
            products[i] = runningProductFromLeft * productFromRight[i];
            runningProductFromLeft *= nums[i];
        }
        return products;
    }
};
