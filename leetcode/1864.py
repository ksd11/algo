class Solution:
    def minSwaps(self, s: str) -> int:
        cnt0, cnt1, odd0, odd1 = 0,0,0,0
        for i,c in enumerate(s):
            if c == '0':
                cnt0 += 1
                if i % 2 == 1:
                    odd0 += 1
            else:
                cnt1 += 1
                if i % 2 == 1:
                    odd1 += 1
        if abs(cnt0 - cnt1) > 1:
            return -1
        
        if cnt0 == cnt1:
            return min(odd0, odd1)
        elif cnt0 > cnt1:
            return odd0
        return odd1