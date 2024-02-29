from typing import List
class Solution:

    def merge(self, left, right):
        l = 0
        r = 0
        res = []
        while l < len(left) and r < len(right):
            if left[l] < right[r]:
                res.append(left[l])
                l += 1
            else:
                res.append(right[r])
                r += 1
        if l < len(left):
            res.extend(left[l:])
        if r < len(right):
            res.extend(right[r:])
        return res

    def sortedSquares(self, nums: List[int]) -> List[int]:
        left = []
        right = []
        for num in nums:
            if num < 0:
                left.append(num*num)
            else:
                right.append(num*num)
        left.reverse()
        return self.merge(left, right)