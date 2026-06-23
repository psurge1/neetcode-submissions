class Solution {
public:
    bool isPalindrome(string s) {
        string preprocessed = "";
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                preprocessed += (c - 'A') + 'a';
            }
            else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                preprocessed += c;
            }
        }
        
        int leftPtr = 0;
        int rightPtr = preprocessed.size() - 1;
        while (leftPtr < rightPtr) {
            if (preprocessed[leftPtr] != preprocessed[rightPtr]) {
                return false;
            }
            ++leftPtr;
            --rightPtr;
        }
        return true;
    }
};
