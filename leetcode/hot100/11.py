class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height)-1
        res = 0
        while(l!=r):
            res = max(res, self.get_volumn(height, l, r))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return res
            

    def get_volumn(self, height, l, r):
        return min(height[r] ,height[l])*(r-l)

