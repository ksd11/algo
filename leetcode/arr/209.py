from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        cursum = 0
        L = 0
        res = 0
        for i,num in enumerate(nums):
            cursum += num
            if cursum >= target:
                while cursum - nums[L] >= target:
                    cursum -= nums[L]
                    L += 1
                if i - L + 1 < res or res == 0:
                    res = i - L + 1
        return res