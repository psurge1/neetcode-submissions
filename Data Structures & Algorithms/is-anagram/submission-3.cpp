class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (n != t.size()) {
            return false;
        }

        char characters[26];
        for (int i = 0; i < 26; ++i) {
            characters[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            ++characters[s[i] - 'a'];
            --characters[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (characters[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
