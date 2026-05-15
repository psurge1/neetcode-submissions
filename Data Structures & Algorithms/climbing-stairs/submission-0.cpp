class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        vector<int> numStepsToReachTop(n, 0);
        numStepsToReachTop[n - 1] = 1;
        numStepsToReachTop[n - 2] = 2;
        for (int i = n - 3; i >= 0; --i) {
            numStepsToReachTop[i] = numStepsToReachTop[i + 1] + numStepsToReachTop[i + 2];
        }

        return numStepsToReachTop[0];
    }
};
