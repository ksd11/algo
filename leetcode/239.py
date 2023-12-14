from typing import List
from bisect import bisect_left

class Ele:
    def __init__(self, num, idx):
        self.num = num
        self.idx = idx

    def __lt__(self, other):
        return self.num < other.num

    def __eq__(self, other):
        return self.num == other.num

    def __repr__(self):
        return str(self.num)

    def getIndex(self):
        return self.idx
    
    def getNum(self):
        return self.num

class Solution:

    # nums是逆序
    def clip(self, queue, ele):
        queue.reverse()
        index = bisect_left(queue, ele)
        if index < len(queue) and queue[index] == ele:
            index +=1
        queue = queue[index:]
        queue.reverse()
        return queue

    def addEle(self, ele, queue):
        queue = self.clip(queue, ele)
        queue.append(ele)
        return queue
    
    def update(self, queue, idx, k):
        if len(queue) and idx - queue[0].getIndex() >= k:
            queue = queue[1:]
        return queue

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        queue = []
        for i,num in enumerate(nums[:k-1]):
            queue = self.addEle(Ele(num,i), queue)

        for i in range(k-1,len(nums)):
            queue = self.update(queue, i, k)
            queue = self.addEle(Ele(nums[i],i), queue)
            res.append(queue[0].getNum())
        return res

s = Solution()
res = s.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3)
print(res)