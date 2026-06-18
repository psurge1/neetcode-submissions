class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> opt(m, vector<int>(n, 0));

        opt[m - 1][n - 1] = 1;
        for (int idxM = m - 2; idxM >= 0; --idxM) {
            opt[idxM][n - 1] = opt[idxM + 1][n - 1];
        }
        for (int idxN = n - 2; idxN >= 0; --idxN) {
            opt[m - 1][idxN] = opt[m - 1][idxN + 1];
        }

        for (int idxM = m - 2; idxM >= 0; --idxM) {
            for (int idxN = n - 2; idxN >= 0; --idxN) {
                opt[idxM][idxN] = opt[idxM + 1][idxN] + opt[idxM][idxN + 1];
            }
        }

        return opt[0][0];
    }
};
