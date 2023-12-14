from typing import List
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        L = 0
        R = len(nums)-1
        while L <= R:
            mid = (L+R)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                R = mid-1
            else:
                L = mid+1
        return -1


s = Solution()
res = s.search([-1,0,3,5,9,12], 2)
print(res)