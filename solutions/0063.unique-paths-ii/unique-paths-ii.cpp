class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            if (!flag && obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            else
            {
                flag = true;
                dp[i][0] = 0;
            }
        }
        flag = false;
        for (int i = 0; i < n; i++)
        {
            if (!flag && obstacleGrid[0][i] == 0)
                dp[0][i] = 1;
            else
            {
                flag = true;
                dp[0][i] = 0;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};