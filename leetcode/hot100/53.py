from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sums = [0] * len(nums)
        for i,num in enumerate(nums):
            if i == 0:
                sums[i] = num
            else:
                sums[i] = sums[i-1]+num

        msum = [0] * len(nums)
        tmp = -int(1e9+7)
        for i,num in enumerate(reversed(sums)):
            if num > tmp:
                tmp = num
            msum[len(sums) - 1- i] = tmp

        res = msum[0]
        for i in range(1,len(msum)):
            if msum[i] - sums[i-1] > res:
                res = msum[i] - sums[i-1]
        
        return res

# print(Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4])) # 6
print(Solution().maxSubArray([-2,1])) # 1
        


