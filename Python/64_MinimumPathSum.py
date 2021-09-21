class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # 1 3 1      1 4 5
        # 1 5 1  =>  2 7 6
        # 4 2 1      4 6 7

        row, col = len(grid), len(grid[0])
        dp = [[0] * col for i in range(row)]

        for i in range(row):
            for j in range(col):
                if i == 0 and j == 0:
                    dp[i][j] = grid[i][j]
                elif i == 0:
                    dp[i][j] = grid[i][j] + dp[i][j - 1]
                elif j == 0:
                    dp[i][j] = grid[i][j] + dp[i - 1][j]
                else:
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]

        return dp[row - 1][col - 1]
