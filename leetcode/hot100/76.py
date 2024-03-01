class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) == 0 or len(t) == 0:
            return ""
        
        counter_target = {}
        for c in t:
            if c in counter_target:
                counter_target[c] += 1
            else:
                counter_target[c] = 1

        counter_source = {}
        left = 0
        right = 0
        while right < len(s):
            if s[right] in counter_target:
                if s[right] in counter_source:
                    counter_source[s[right]] += 1
                else:
                    counter_source[s[right]] = 1
                if self.is_match(counter_source, counter_target):
                    break
            right += 1

        if right == len(s):
            return "" # not match
        
        # 寻找left的边界
        left = self.left_borader(s, left, counter_source, counter_target)

        min_len = right - left + 1
        res = s[left:right+1]

        while right < len(s):
            c = s[left] # 缺失字符
            left += 1 # 此时left指向的字符不在counter_target中
            
            # 从right找缺失字符
            right += 1
            while(right < len(s) and s[right] != c):
                if s[right] in counter_target:
                    counter_source[s[right]] += 1
                right += 1

            if right == len(s):
                break
            
            # 继续探测left边界
            left = self.left_borader(s, left, counter_source, counter_target)
            
            if right - left + 1 < min_len:
                min_len = right - left + 1
                res = s[left:right+1]
        return res
    
    def left_borader(self, s, left, counter_source, counter_target):
        while True:
            while s[left] not in counter_target:
                left += 1
            
            counter_source[s[left]] -= 1
            if not self.is_match(counter_source, counter_target):
                counter_source[s[left]] += 1
                break
            left += 1
        return left
    
    def is_match(self, counter_source, counter_target):
        for k in counter_target:
            if k not in counter_source or counter_source[k] < counter_target[k]:
                return False
        return True
    
print(Solution().minWindow("ADOBECODEBANC", "ABC"))