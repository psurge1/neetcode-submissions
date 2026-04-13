class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (n != t.size()) {
            return false;
        }

        unordered_map<char, int> char_count;
        for (int i = 0; i < n; ++i) {
            ++char_count[s[i]];
            --char_count[t[i]];
        }
        for (const pair<char, int>& kv : char_count) {
            if (kv.second != 0) {
                return false;
            }
        }
        return true;
    }
};
