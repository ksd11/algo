from typing import List
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mp = {}
        for num in nums:
            mp[num] = True

        
        res = 0
        for num in nums:
            if not mp[num]:
                continue

            left = 0
            ele = num - 1 - left
            while ele in mp and mp[ele]:
                mp[ele] = False
                left += 1
                ele = num - 1 - left
            
            right = 0
            ele = num + 1 + right
            while ele in mp and mp[ele]:
                mp[ele] = False
                right += 1
                ele = num + 1 + right

            if res < left + right + 1:
                res = left + right + 1
        return res

        

        
        