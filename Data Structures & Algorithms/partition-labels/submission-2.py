class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        """
        preprocess the array by finding the first and last index of every character in the string
        treat these as intervals
        merge overlapping intervals
        return the resulting interval sizes
        """

        interval = dict()
        for idx in range(len(s)):
            char = s[idx]
            if char not in interval:
                interval[char] = [idx, idx]
            interval[char][1] = idx
        
        intervals = deque()
        seen = set()
        for char in s:
            if char not in seen:
                intervals.append(interval[char])
                seen.add(char)
        print(interval)
        print(intervals)
    
        res = []
        while len(intervals) > 0:
            start, end = intervals.popleft()
            if len(intervals) == 0:
                res.append(end - start + 1)
            else:
                next_start, next_end = intervals[0]
                if next_start > end:
                    res.append(end - start + 1)
                else:
                    intervals[0][0] = start
                    intervals[0][1] = max(intervals[0][1], end)
        return res
