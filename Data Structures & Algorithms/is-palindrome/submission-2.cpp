class Solution {
private:
    bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
public:
    bool isPalindrome(string s) {
        int leftPtr = 0;
        int rightPtr = s.size() - 1;

        while (leftPtr < rightPtr) {
            while (leftPtr < rightPtr && !isAlpha(s[leftPtr])) {
                ++leftPtr;
            }
            while (rightPtr > leftPtr && !isAlpha(s[rightPtr])) {
                --rightPtr;
            }
            if (tolower(s[leftPtr]) != tolower(s[rightPtr])) {
                return false;
            }
            ++leftPtr;
            --rightPtr;
        }
        return true;
    }
};
