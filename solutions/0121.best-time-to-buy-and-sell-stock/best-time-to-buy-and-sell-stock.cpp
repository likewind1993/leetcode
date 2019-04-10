class Solution {
public:
	int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
		int n = prices.size();
		vector<int> dp(n + 1);
		dp[0] = 0;
		int min_val = prices[0];
		for (int i = 1; i < n; i++) {
			if (min_val < prices[i]) {
				dp[i] = max(dp[i - 1], prices[i] - min_val);
			}
			else {
				dp[i] = dp[i - 1];
				min_val = prices[i];
			}
		}
		return dp[n - 1];

	}
};