class Solution:
    def longestPalindrome(self, s: str) -> str:
        # O(n^2) time, O(n) space
        new_s = ["#"]
        for char in s:
            new_s.append(char)
            new_s.append("#")

        s_new = "".join(new_s)
        palindrome_left = 0
        palindrome_right = 0
        for idx in range(len(s_new)):
            left = idx
            right = idx
            while left >= 0 and right < len(s_new) and s_new[left] == s_new[right]:
                if right - left > palindrome_right - palindrome_left:
                    palindrome_right = right
                    palindrome_left = left
                left -= 1
                right += 1
        
        palindrome = []
        for idx in range(palindrome_left, palindrome_right + 1):
            if s_new[idx] != "#":
                palindrome.append(s_new[idx])
        return "".join(palindrome)