class Solution {
private:
    void genCombinations(int idx, int target, vector<int>& addends, vector<vector<int>>& combinations, const vector<int>& candidates) {
        if (target == 0) {
            combinations.push_back(addends);
            return;
        }
        if (target < 0 || idx == candidates.size()) {
            return;
        }

        int candidate = candidates[idx];
        addends.push_back(candidate);
        genCombinations(idx + 1, target - candidates[idx], addends, combinations, candidates);
        addends.pop_back();
        
        while (idx < candidates.size() && candidates[idx] == candidate) {
            ++idx;
        }
        genCombinations(idx, target, addends, combinations, candidates);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> combinations;
        vector<int> addends;
        genCombinations(0, target, addends, combinations, candidates);
        return combinations;
    }
};
