from typing import List
class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        res = 0
        for i in range(0, 2**len(nums)):
            subset = []
            for j in range(0, len(nums)):
                if i & 1<<j:
                    subset.append(nums[j])
        
            tmp = 0
            for num in subset:
                tmp ^= num
            res += tmp
        
        return res

print(Solution().subsetXORSum([1,3])) # 6