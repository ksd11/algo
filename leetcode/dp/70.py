class Solution:

    def climbStairs(self, n: int) -> int:
        if not hasattr(self, "dp"):
            self.dp = [-1]*(n+1)
            self.dp[1] = 1
            if n > 1:
                self.dp[2] = 2

        if self.dp[n]!=-1:
            return self.dp[n]

        self.dp[n] = self.climbStairs(n-1)+self.climbStairs(n-2)
        return self.dp[n]
    
print(Solution().climbStairs(3))  # 3