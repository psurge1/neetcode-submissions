class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> productUntil(n, 1);
        vector<int> productUptil(n, 1);
        for (int i = 1; i < n; ++i) {
            productUntil[i] = productUntil[i - 1] * nums[i - 1];
            productUptil[n - i - 1] = productUptil[n - i] * nums[n - i];
        }

        vector<int> products(n);
        for (int i = 0; i < n; ++i) {
            products[i] = productUntil[i] * productUptil[i];
        }
        return products;
    }
};
