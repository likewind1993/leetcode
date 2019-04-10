class Solution {
public:
    int countNumbersWithUniqueDigits(int n)
    {
        vector<int> dp(n+1);
        dp[0] = 1; dp[1] = 10;
        for (int i = 2; i <= n; i++)
        {
            if (i > 10)
                dp[i] = dp[i - 1];
            else
            {
                int ans = 9, num = 9, cnt = i;
                ans = ans * num;
                while (cnt > 2 && cnt <= 10)
                {
                    num--;
                    cnt--;
                    ans = ans*num;
                }
                dp[i] = dp[i - 1] + ans;
            }
        }
        return dp[n];
    }
};