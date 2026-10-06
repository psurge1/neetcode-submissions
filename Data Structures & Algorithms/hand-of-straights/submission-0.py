class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        card_counts = dict()
        heap = []
        for h in hand:
            if h not in card_counts:
                card_counts[h] = 0
            card_counts[h] += 1
            heapq.heappush(heap, h)
        
        while len(heap) > 0:
            min_val = heapq.heappop(heap)
            while min_val not in card_counts and len(heap) > 0:
                min_val = heapq.heappop(heap)
            if min_val not in card_counts:
                return True
            
            card_counts[min_val] -= 1
            if card_counts[min_val] == 0:
                card_counts.pop(min_val)
            for k in range(groupSize - 1):
                min_val += 1
                if min_val not in card_counts:
                    return False
                card_counts[min_val] -= 1
                if card_counts[min_val] == 0:
                    card_counts.pop(min_val)
        return True