class Solution {
private:
    void dfs(vector<string>& res, string& builder, const string& digits, int index, unordered_map<char, vector<char>>& mapping) {
        if (index == digits.size()) {
            res.push_back(builder);
        }
        else {
            char digit = digits[index];
            for (const char lc : mapping[digit]) {
                builder.push_back(lc);
                dfs(res, builder, digits, index + 1, mapping);
                builder.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }

        unordered_map<char, vector<char>> mapping;
        mapping['2'] = {'a', 'b', 'c'};
        mapping['3'] = {'d', 'e', 'f'};
        mapping['4'] = {'g', 'h', 'i'};
        mapping['5'] = {'j', 'k', 'l'};
        mapping['6'] = {'m', 'n', 'o'};
        mapping['7'] = {'p', 'q', 'r', 's'};
        mapping['8'] = {'t', 'u', 'v'};
        mapping['9'] = {'w', 'x', 'y', 'z'};

        string builder = "";
        dfs(result, builder, digits, 0, mapping);

        return result;
    }
};
