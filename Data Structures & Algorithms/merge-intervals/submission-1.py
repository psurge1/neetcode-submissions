class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        merged_intervals = []

        prev_start = -1
        prev_end = -1
        for interval in intervals:
            if interval[0] <= prev_end:
                prev_end = max(prev_end, interval[1])
            else:
                if prev_start != -1:
                    merged_intervals.append([prev_start, prev_end])
                prev_start = interval[0]
                prev_end = interval[1]
        merged_intervals.append([prev_start, prev_end])
        
        return merged_intervals