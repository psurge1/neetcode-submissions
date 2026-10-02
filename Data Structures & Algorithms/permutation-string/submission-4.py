class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        frequency_table = [0] * 26
        for char in s1:
            frequency_table[ord(char) - ord("a")] += 1
        
        left = 0
        right = 0
        while right < len(s2):
            char = s2[right]
            frequency_table[ord(char) - ord("a")] -= 1
            while left < right + 1 and frequency_table[ord(char) - ord("a")] < 0:
                frequency_table[ord(s2[left]) - ord("a")] += 1
                left += 1
            if sum(frequency_table) == 0:
                return True
            right += 1
        return False