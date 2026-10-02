class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest_length = 0
        left_ptr = 0
        right_ptr = 0
        seen_chars = set()
        while right_ptr < len(s):
            while s[right_ptr] in seen_chars:
                seen_chars.discard(s[left_ptr])
                left_ptr += 1
            seen_chars.add(s[right_ptr])
            longest_length = max(longest_length, right_ptr - left_ptr + 1)
            right_ptr += 1
        return longest_length