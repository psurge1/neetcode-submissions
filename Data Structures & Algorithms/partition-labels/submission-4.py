class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last_occurence = [0] * 26
        n = len(s)
        for i in range(n):
            last_occurence[ord(s[i]) - ord("a")] = i
        
        result = []
        window_size = 0
        end = 0
        for i in range(n):
            window_size += 1
            end = max(end, last_occurence[ord(s[i]) - ord("a")])
            if i == end:
                result.append(window_size)
                window_size = 0
        return result