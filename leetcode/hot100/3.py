
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        left = 0
        right = 0
        res = 1
        pos = {s[0]:0} # 记录每个字符的位置
        right += 1
        while right < len(s):
            if s[right] in pos and pos[s[right]] >= left:
                res = max(res, right-left)
                left = pos[s[right]]+1
                
            pos[s[right]] = right
            right += 1

        return max(res, right-left)
    
# print(Solution().lengthOfLongestSubstring("abcabcbb"))
print(Solution().lengthOfLongestSubstring("abba"))