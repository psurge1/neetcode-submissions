class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1_size = len(s1)
        s2_size = len(s2)
        if len(s3) != s1_size + s2_size:
            return False
        
        prev = [False for _ in range(s2_size + 1)]
        prev[0] = True
        for idx2 in range(1, s2_size + 1):
            prev[idx2] = s2[idx2 - 1] == s3[idx2 - 1] and prev[idx2 - 1]

        for idx1 in range(1, s1_size + 1):
            curr = [False for _ in range(s2_size + 1)]
            for idx2 in range(0, s2_size + 1):
                target_char = s3[idx1 + idx2 - 1]
                if idx2 == 0:
                    curr[idx2] = target_char == s1[idx1 - 1] and prev[idx2]
                elif target_char == s1[idx1 - 1] and prev[idx2]:
                    curr[idx2] = True
                elif target_char == s2[idx2 - 1] and curr[idx2 - 1]:
                    curr[idx2] = True
            
            prev = curr
        
        return prev[s2_size]