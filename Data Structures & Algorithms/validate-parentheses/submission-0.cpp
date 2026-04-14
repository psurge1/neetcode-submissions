class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> pairs;
        pairs[')'] = '(';
        pairs[']'] = '[';
        pairs['}'] = '{';

        for (char c : s) {
            if (pairs.find(c) == pairs.end()) {
                stk.push(c);
            }
            else {
                if (stk.size() == 0 || stk.top() != pairs[c]){
                    return false;
                }
                stk.pop();
            }
        }

        return stk.empty();
    }
};
