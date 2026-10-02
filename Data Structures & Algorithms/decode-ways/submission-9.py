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

        derived from O(n) space solution

        O(n) time, O(1) space
        """

        n = len(s)
        if s[0] == "0":
            return 0
        if n == 1:
            return 1
        
        prev_ways = 0
        curr_ways = 1

        for i in range(n - 1, -1, -1):
            next_ways = 0
            if s[i] != "0":
                if int(s[i:i + 2]) <= 26:
                    next_ways += prev_ways
                next_ways += curr_ways
            prev_ways = curr_ways
            curr_ways = next_ways
        return curr_ways