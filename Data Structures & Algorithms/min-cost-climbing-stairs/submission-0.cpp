class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> costToReachTop(n, 0);
        costToReachTop[n - 1] = cost[n - 1];
        costToReachTop[n - 2] = cost[n - 2];

        for (int step = n - 3; step >= 0; --step) {
            costToReachTop[step] = cost[step] + min(costToReachTop[step + 1], costToReachTop[step + 2]);
        }

        return min(costToReachTop[0], costToReachTop[1]);
    }
};
