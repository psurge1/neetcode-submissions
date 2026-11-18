"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        interval_tuples = []
        for interval in intervals:
            interval_tuples.append((interval.start, interval.end))
        
        interval_tuples.sort()

        prev_end = 0
        for tup in interval_tuples:
            if tup[0] < prev_end:
                return False
            prev_end = tup[1]
        return True