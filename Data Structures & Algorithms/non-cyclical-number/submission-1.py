class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        seen.add(n)

        while n != 1:
            s = 0
            while n > 0:
                s += (n % 10)**2
                n //= 10
            n = s
            if n in seen:
                return False
            seen.add(n)
        
        return True