class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        buckets = [0] * 101
        for stone in stones:
            buckets[stone] += 1
        
        heaviest = 100
        second_heaviest = 99
        while second_heaviest > 0:
            print(buckets)
            while heaviest > 0 and buckets[heaviest] % 2 == 0:
                heaviest -= 1
            second_heaviest = min(heaviest - 1, second_heaviest)
            while second_heaviest > 0 and buckets[second_heaviest] == 0:
                second_heaviest -= 1
            if second_heaviest <= 0:
                return heaviest
            buckets[heaviest] = 0
            buckets[second_heaviest] -= 1
            diff = heaviest - second_heaviest
            buckets[diff] += 1
            heaviest = max(second_heaviest, diff)
        
        return heaviest