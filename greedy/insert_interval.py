class Solution(object):
    def insert(self, intervals, newInterval):
        # first we will solve the left most pattern which not overlapp and add them to our resultant arr then we will handle the middle part where overlapping occurs and take the range(min, max) as arr and at last add the remaining elements of the arr
        n = len(intervals); i=0
        res = []

        # for leftmost condtions 
        while(i < n and newInterval[0] > intervals[i][1]):
            res.append(intervals[i])
            i += 1 

        # for overlapping elements
        while(i < n and newInterval[1] >= intervals[i][0]):
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1
        res.append(newInterval)
        
        # for  the remaining elements
        while(i < n):
            res.append(intervals[i])
            i += 1

        return res