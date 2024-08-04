class Solution(object):
    def canJump(self, nums):
        n = len(nums)
        max_ind = 0
        for i in range(0, n):
            if i > max_ind:
                return False
            else:
                max_ind = max(max_ind, i+ nums[i])   
                if max_ind > n:
                    return True

        return True
        