class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        frequency_table = [0] * 26
        left_ptr = 0
        right_ptr = 0
        max_width = 0

        while right_ptr < len(s):
            # window_width = right_ptr - left_ptr + 1
            # acceptable if window_width - max(frequency_table) <= k
            frequency_table[ord(s[right_ptr]) - ord("A")] += 1
            window_width = right_ptr - left_ptr + 1
            if window_width - max(frequency_table) <= k:
                max_width = max(max_width, window_width)
            else:
                # key point: we never want to shrink the window, only grow it
                frequency_table[ord(s[left_ptr]) - ord("A")] -= 1
                left_ptr += 1
            right_ptr += 1



        return max_width