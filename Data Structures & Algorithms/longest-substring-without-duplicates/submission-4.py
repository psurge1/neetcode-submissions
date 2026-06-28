class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        opening = 0
        closing = 0
        char_indeces = dict()
        max_len = 0

        while closing < len(s):
            char = s[closing]
            if char in char_indeces.keys() and char_indeces[char] >= opening:
                max_len = max(max_len, closing - opening)
                opening = char_indeces[char] + 1
            char_indeces[char] = closing
            closing += 1
        max_len = max(max_len, closing - opening)

        return max_len