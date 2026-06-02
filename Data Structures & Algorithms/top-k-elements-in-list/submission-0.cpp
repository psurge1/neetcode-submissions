using numberFrequencies = pair<int, int>;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<numberFrequencies> heap;
        unordered_map<int, int> frequencyTable;
        for (int i = 0; i < nums.size(); ++i) {
            ++frequencyTable[nums[i]];
        }

        for (const auto& entry : frequencyTable) {
            heap.emplace(entry.second, entry.first);
        }

        vector<int> topFrequent;
        for (int i = 0; i < k; ++i) {
            auto ithMostFrequent = heap.top();
            heap.pop();
            topFrequent.push_back(ithMostFrequent.second);
        }

        return topFrequent;
    }
};
