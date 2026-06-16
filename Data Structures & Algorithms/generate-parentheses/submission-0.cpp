class Solution {
private:
    void findCombos(int openers, int closers, string& parenthesis, vector<string>& combos) {
        if (openers == 0 && closers == 0) {
            combos.push_back(parenthesis);
            return;
        }
        if (closers > openers) {
            parenthesis += ')';
            findCombos(openers, closers - 1, parenthesis, combos);
            parenthesis.pop_back();
        }
        if (openers > 0) {
            parenthesis += '(';
            findCombos(openers - 1, closers, parenthesis, combos);
            parenthesis.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesisCombos;
        string parenthesis = "";
        findCombos(n, n, parenthesis, parenthesisCombos);
        return parenthesisCombos;
    }
};
