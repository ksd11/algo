import sys
input = lambda:sys.stdin.readline().strip()
res = 0
n = int(input())
a = list(map(int, input().split()))
ans = 0
def add(x):
    while x <= n + n + 1:
        f[x] += 1
        x += x & -x

def get(x):
    res = 0
    while x > 0:
        res += f[x]
        x -= x & -x
    return res
f = [0] * (n + n + 2)
ans = 0
add(n + 1)
for v in a:
    if v == 1:
        ans -= 1
    else:
        ans += 1
    # res记录众数为2的个数
    res += get(ans + n)
    add(ans + n + 1) # 原数+n+1是在树状数组中的位置

# 区间总共有 n*(n+1)/2个
r = n * (n + 1) // 2 - res
print(res * 2 + r)