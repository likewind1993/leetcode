#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s)
    {
        const int n = s.size();
        if(n == 0) 
            return "";
        int left = 0, right = 0, prev = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i) {
            dp[i][i] = true;
            if(s[prev] == s[i]) {
                dp[prev][i] = true;
                left = prev;
                right = i; 
            }
                
            prev = i;
        }
        
        for(int i = n-2; i>=0; --i) {
            for(int j = i+1; j<n; ++j) {
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if(j - i > right - left) {
                        right = j;
                        left = i;
                    }
                }
            }
        }
        return s.substr(left, right-left + 1);
    }
};


int main()
{
    string a = "cbba";
    Solution solution;
    cout<<solution.longestPalindrome(a)<<endl;
    return 0;
}