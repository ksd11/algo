class Solution:
    


    """ def numberOfSets(self, n: int, k: int) -> int:
        res = 0
        if n == k+1:
            return 1
        if k == 1:
            return int((n-1)*n/2)
        if arr[n][k] != 0:
            return arr[n][k]

        for i in range(1, n-k+1):
            res += self.numberOfSets(n-i, k-1)
        arr[n][k] = (res + self.numberOfSets(n-1, k)) % C
        return arr[n][k] """
    def debug(self, i, j, v):
        pass
        # print(f"arr[{i}][{j}] = {v}")
    

    # def numberOfSets(self, n: int, k: int) -> int:
    #     M = 1000 + 5

    #     arr = [[1 if i-1==j else 0  for j in range(M)] for i in range(M)]

    #     C = 10**9 + 7

    #     for i in range(2, n+1):
    #         self.debug(i,i-1,arr[i][i-1])

    #     if arr[n][k] != 0:
    #         return arr[n][k]
    #     j_low = 1

    #     for i  in range(3, n+1):
    #         if i == n:
    #             j_low = k
    #         for j in reversed(range(j_low,i-1)):
    #             for t in range(1, i-j+1):
    #                 if j == 1:
    #                     flag = True
    #                     arr[i][j] = int((i-1)*i/2) % C
    #                     self.debug(i, j, arr[i][j])
    #                     break
    #                 else:
    #                     arr[i][j] = (arr[i][j]+arr[i-t][j-1]) % C
    #             if not flag:
    #                 arr[i][j] = (arr[i][j] + arr[i-1][j])%C
    #                 self.debug(i, j, arr[i][j])
    #             else:
    #                 flag = False
    #     return arr[n][k]
    
    def numberOfSets(self, n: int, k: int) -> int:
        M = 1000 + 5

        arr = [[1 if i-1==j else 0  for j in range(M)] for i in range(M)]

        C = 10**9 + 7

        # 累积和
        culm_sum = [arr[i+1][i] for i in range(M-1)]

        if arr[n][k] != 0:
            return arr[n][k]
        j_low = 1

        for i  in range(3, n+1):
            if i == n:
                j_low = k
            for j in reversed(range(j_low,i-1)):
                if j == 1:
                    arr[i][j] = int((i-1)*i/2) % C
                else:
                    arr[i][j] = (arr[i][j]+culm_sum[j-1]) % C
                    arr[i][j] = (arr[i][j]+arr[i-1][j])%C
                
                culm_sum[j] = (culm_sum[j] + arr[i][j]) % C
        return arr[n][k]


        




if __name__ == '__main__':
    solution = Solution()
    # n ,k = 5, 3
    n ,k = 30, 7
    question_ouput = solution.numberOfSets(n,k)
    print(question_ouput)