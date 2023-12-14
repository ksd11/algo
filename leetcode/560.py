class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        res = 0
        cursum = [0 for i in range(len(nums))]
        cursum[0] = nums[0]
        hash_table = {0: 1}
        for i in range(1,len(nums)):
            cursum[i] = cursum[i-1] + nums[i]

        # [.., i]
        for i in cursum:
            if i - k in hash_table:
                res += hash_table[i-k]
            if i in hash_table:
                hash_table[i] += 1
            else:
                hash_table[i] = 1             
        return res
        
        # [i:j+1]
        # for i in range(len(cursum)):
        #     for j in range(i,len(cursum)):
        #         if i != 0:
        #             csum = cursum[j] - cursum[i-1]
        #         else:
        #             csum = cursum[j]
        #         if csum == k:
        #             res += 1
        # return res

if __name__ == '__main__':
    solution = Solution()
    # num1 = [1,2,3]
    # k = 3
    # num1 = [1,1,1]
    # k = 2
    num1 = [1]
    k = 0
    print(solution.subarraySum(nums=num1, k=k))