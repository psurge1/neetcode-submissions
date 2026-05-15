class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev = cost[n - 1];
        int curr = cost[n - 2];

        for (int step = n - 3; step >= 0; --step) {
            int stepCost = cost[step] + min(curr, prev);
            prev = curr;
            curr = stepCost;
        }

        return min(prev, curr);
    }
};
