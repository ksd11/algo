from typing import List
class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        res = 0
        for i in range(1,len(height)):
            if height[i] < height[left]:
                continue
            else:
                if i - left > 1:
                    # left ~ i这段区间可以存水
                    vol = 0
                    for j in range(left, i):
                        vol += height[j]
                    res += height[left]*(i-left) - vol

                left = i
        
        # left是最高的
        right = len(height)-1
        for i in range(right-1, left-1, -1):
            if height[i] < height[right]:
                continue
            
            # i ~ right这段区间可以存水
            if right - i > 1:
                vol = 0
                for j in range(i+1, right+1):
                    vol += height[j]
                res += height[right]*(right-i) - vol

            right = i

        return res



print(Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1])) # 6
print(Solution().trap([4,2,0,3,2,5]))
print(Solution().trap([4,2,3]))