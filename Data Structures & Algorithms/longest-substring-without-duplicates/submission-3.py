class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars_seen = dict()
        start_ptr = 0
        end_ptr = 0
        max_size = 0

        while end_ptr < len(s):
            if s[end_ptr] in chars_seen.keys():
                max_size = max(max_size, end_ptr - start_ptr)
                new_start_ptr = chars_seen[s[end_ptr]] + 1
                while start_ptr < new_start_ptr:
                    chars_seen.pop(s[start_ptr])
                    start_ptr += 1
            chars_seen[s[end_ptr]] = end_ptr
            end_ptr += 1
        
        max_size = max(max_size, end_ptr - start_ptr)

        return max_size
