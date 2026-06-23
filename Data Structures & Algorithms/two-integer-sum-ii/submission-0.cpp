class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftIdx = 0;
        int rightIdx = numbers.size() - 1;
        while (leftIdx < rightIdx) {
            int numSum = numbers[leftIdx] + numbers[rightIdx];
            if (numSum == target) {
                return vector<int>{leftIdx + 1, rightIdx + 1};
            }
            else if (numSum < target) {
                ++leftIdx;
            }
            else {
                --rightIdx;
            }
        }
        return vector<int>{-1, -1};
    }
};
