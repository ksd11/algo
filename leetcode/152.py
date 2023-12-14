import sys
class Solution:
    def max_min_product(self, nums: list[int]) -> int:
        l_max = -sys.maxsize
        l_min = sys.maxsize
        val = 1
        for i in nums:
            val = val * i 
            if val > l_max:
                l_max = val
            if val < l_min:
                l_min = val
        return l_max, l_min

    def maxProduct(self, nums: list[int]) -> int:
        length = len(nums)
        if length == 1:
            return nums[0]
        
        mid = length // 2
        left = nums[:mid]
        right = nums[mid:]
        left_max = self.maxProduct(left)
        right_max = self.maxProduct(right)
        
        l_max, l_min = self.max_min_product(left[::-1])
        r_max, r_min = self.max_min_product(right)
        mid_max = max(l_max * r_max, l_min * r_min)

        return max(left_max, right_max, mid_max)


if __name__ == '__main__':
    solution = Solution()
    # num1 = [2,3,-2,4]
    num1 = [-2, 0, -1]
    print(solution.maxProduct(nums=num1))