class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int numDigits = digits.size();
        reverse(digits.begin(), digits.end());
        ++digits[0];
        for (int place = 0; place < numDigits - 1; ++place) {
            if (digits[place] >= 10) {
                digits[place] -= 10;
                ++digits[place + 1];
            }
        }
        if (digits[numDigits - 1] >= 10) {
            digits[numDigits - 1] -= 10;
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
