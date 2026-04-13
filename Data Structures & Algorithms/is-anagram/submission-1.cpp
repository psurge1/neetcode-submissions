class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> char_count;

        for (char c : s) {
            ++char_count[c];
        }
        for (char c : t) {
            --char_count[c];
        }
        for (const pair<char, int>& kv : char_count) {
            if (kv.second != 0) {
                return false;
            }
        }
        return true;
    }
};
