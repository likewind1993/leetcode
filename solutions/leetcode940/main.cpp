#include <iostream>
#include <string>
#include <vector>
using namespace std;

//code Ref:
//https://leetcode.com/articles/distinct-subsequences-ii/
class Solution {
public:
    int distinctSubseqII(string S)
    {
        const int MOD = 1000000007;
        int n = S.size();
        vector<int> last(26);
        vector<int> dp(n+1);
        dp[0] = 1;

        for(int i = 0; i<last.size(); ++i) last[i] = -1;

        for (int i = 0; i < n; ++i) {
            int x = S[i] - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if(last[x] >= 0)
                dp[i+1] -= dp[last[x]];
            dp[i+1] %= MOD;
            last[x] = i;
        }
        dp[n]--;
        if (dp[n]<0) dp[n] += MOD;

        return dp[n];
    }
};
int main() {
    string str = "aba";
    Solution solution;

    cout<<solution.distinctSubseqII(str)<<endl;

    return 0;
}