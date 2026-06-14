class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        subs.push_back({});

        for (int num : nums) {
            for (int idx = 0, n = subs.size(); idx < n; ++idx) {
                vector<int> sub(subs[idx]);
                sub.push_back(num);
                subs.push_back(std::move(sub));
            }
        }
        return subs;
    }
};
