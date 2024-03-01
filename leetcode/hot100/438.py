from typing import List
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        counter = {} # 字符串p各个字符个数
        size = len(p)
        res = []
        pos = {}
        left = 0

        # 统计P中各个字符出现的次数
        for c in p:
            if c in counter:
                counter[c] += 1
            else:
                counter[c] = 1

        cnt = counter.copy()
        pos = self.pos_clear(pos)
        for i,c in enumerate(s):
            # 如果c在counter中，则更新cnt和pos
            if c in counter:
                if c in cnt:
                    # left = pos[c]+1
                    cnt[c] -= 1
                    pos[c].append(i)
                    if cnt[c] == 0:
                        cnt.pop(c)
                else:
                    idx = pos[c].pop(0)
                    pos[c].append(i)
                    for j in range(left, idx):
                        if s[j] in cnt:
                            cnt[s[j]] += 1
                        else:
                            cnt[s[j]] = 1
                        pos[s[j]].pop(0)
                    left = idx+1

                # 直到所有字符都出现了size次，则输出匹配
                if len(cnt) == 0:
                    res.append(left)
                    cnt[s[left]] = 1
                    pos[s[left]].pop(0)
                    left += 1
            
            # 否则，由于不在子串中，所以清空pos和cnt
            else:
                left = i+1
                cnt =counter.copy()
                pos = self.pos_clear(pos)
        return res
    
    def pos_clear(self, pos):
        for i in range(26):
            pos[chr(i+97)] = []
        return pos

print(Solution().findAnagrams("cbaebabacd", "abc"))
print(Solution().findAnagrams("abab", "ab"))
print(Solution().findAnagrams("abaacbabc", "abc"))

