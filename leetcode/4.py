class Solution:
    # 复杂度O((m+n)*ln(m+n)) 对于这道题的数据量来说，应该是可以接受的
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()
        length = len(nums1)
        if length % 2 == 0:
            return (nums1[length//2] + nums1[length//2 - 1])/2
        else:
            return nums1[length//2]



if __name__ == '__main__':
    solution = Solution()
    num1 = [1,3]
    num2 = [2]
    question_ouput = solution.findMedianSortedArrays(num1, num2)
    print(question_ouput)