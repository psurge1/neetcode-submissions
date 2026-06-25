class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1_size = len(s1)
        s2_size = len(s2)
        if len(s3) != s1_size + s2_size:
            return False
        
        table = [[False] * (s2_size + 1) for _ in range(s1_size + 1)]
        table[0][0] = True
        for idx1 in range(1, s1_size + 1):
            table[idx1][0] = s1[idx1 - 1] == s3[idx1 - 1] and table[idx1 - 1][0]
        for idx2 in range(1, s2_size + 1):
            table[0][idx2] = s2[idx2 - 1] == s3[idx2 - 1] and table[0][idx2 - 1]

        for idx1 in range(1, s1_size + 1):
            for idx2 in range(1, s2_size + 1):
                if s1[idx1 - 1] == s3[idx1 + idx2 - 1] and table[idx1 - 1][idx2]:
                    table[idx1][idx2] = True
                elif s2[idx2 - 1] == s3[idx1 + idx2 - 1] and table[idx1][idx2 - 1]:
                    table[idx1][idx2] = True
                else:
                    table[idx1][idx2] = False
        
        return table[s1_size][s2_size]