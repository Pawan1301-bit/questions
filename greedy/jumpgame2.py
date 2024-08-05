class Solution(object):
    def jump(self, nums):
        n = len(nums)
        left =0 
        right =0
        jump =0

        while right < n-1:
            farthest = 0
            for i in range (left , right+1):
                farthest = max(farthest, i + nums[i])
            jump = jump+1
            left = right+1
            right = farthest

        return jump
        