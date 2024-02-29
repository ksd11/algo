from typing import List

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0 for _ in range(n)] for _ in range(n)]
        L = 0
        R = n-1
        U = 0
        D = n-1
        num = 1
        while L <= R and U <= D:
            # left -> right
            for i in range(L, R+1):
                res[U][i] = num
                num += 1
            U += 1
            # up->down
            for i in range(U, D+1):
                res[i][R] = num
                num += 1
            R -= 1
            # right -> left
            for i in range(R, L-1, -1):
                res[D][i] = num
                num += 1
            D -= 1
            # up -> down
            for i in range(D, U-1, -1):
                res[i][L] = num
                num += 1
            L += 1
        return res

print(Solution().generateMatrix(n=3))