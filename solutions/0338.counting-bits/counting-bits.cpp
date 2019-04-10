class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> dp(num + 1);
		dp[0] = 0;
		int cur = 0;
		for (int i = 1; i <= num; i++) {
			if (pow(2, cur+1) == i) {
				dp[i] = 1;
				cur += 1;
			}
			else {
				dp[i] = dp[i - pow(2, cur)]+1;
			}
		}
		return dp;

	}
};
