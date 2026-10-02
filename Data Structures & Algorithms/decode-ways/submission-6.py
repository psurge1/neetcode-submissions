class Solution:
    def numDecodings(self, s: str) -> int:
        """
        OPT(i) tells us how many ways there are to decode characters i through n - 1 of s i.e. s[i:]
        let OPT(i) = {
            0 if s[i] == 0
            1 if i == n - 1
            OPT(i + 1) + OPT(i + 2) if int(s[i - 1:i + 1]) <= 26
            OPT(i + 1) otherwise
        }

        there was one way to reach the end starting at n
        there is no way to reach the end starting at n + 1
        thus, dp[n] = 1, and dp[n + 1] = 0
        it makes sense in hindsight
        """

        n = len(s)
        if s[0] == "0":
            return 0
        if n == 1:
            return 1
        
        dp = [0] * (n + 2)
        dp[n] = 1
        dp[n + 1] = 0

        for i in range(n - 1, -1, -1):
            if s[i] == "0":
                dp[i] = 0
            else:
                if int(s[i:i + 2]) <= 26:
                    dp[i] += dp[i + 2]
                dp[i] += dp[i + 1]
        return dp[0]