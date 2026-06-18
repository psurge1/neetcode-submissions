class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int sz1 = text1.size();
        int sz2 = text2.size();

        // opt (i, j) gives the longest subsequence considering the first i characters of text1 and first j characters of text2 
        vector<vector<int>> opt(sz1 + 1, vector<int>(sz2 + 1, 0));

        for (int i = 1; i <= sz1; ++i) {
            for (int j = 1; j <= sz2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    opt[i][j] = 1 + opt[i - 1][j - 1];
                }
                else {
                    opt[i][j] = max(opt[i - 1][j], opt[i][j - 1]);
                }
            }
        }

        return opt[sz1][sz2];
    }
};
