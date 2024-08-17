class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        # reverse of the n meeting in one room
        n = len(intervals)
        intervals.sort(key = lambda x:x[1])

        # now count the number of max numbere of non overlapping intervals
        cnt = 1; last_element = intervals[0][1]

        for i in range(1 , n):
            if intervals[i][0] >= last_element:
                cnt += 1
                last_element = intervals[i][1]

        return n-cnt
        