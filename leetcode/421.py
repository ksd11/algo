from typing import List
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        res = 0
        mask = 0
        for i in range(31, -1, -1):
            mask |= 1 << i
            s = set()
            for num in nums:
                s.add(num & mask)
            temp = res | 1 << i
            for prefix in s:
                if temp ^ prefix in s:
                    res = temp
                    break
        return res
    
print(Solution().findMaximumXOR([3, 10, 5, 25, 2, 8])) # 28