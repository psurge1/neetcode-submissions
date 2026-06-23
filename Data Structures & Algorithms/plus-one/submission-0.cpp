class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> solution;

        int numDigits = digits.size();
        ++digits[numDigits - 1];

        int idx = numDigits - 1;
        while (idx > 0 && digits[idx] >= 10) {
            digits[idx] -= 10;
            ++digits[idx - 1];
            --idx;
        }
        
        if (digits[0] >= 10) {
            digits[0] -= 10;
            solution.push_back(1);
        }

        for (int digit : digits) {
            solution.push_back(digit);
        }


        return solution;
    }
};
