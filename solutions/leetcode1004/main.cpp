#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& A, int K)
    {
        int n = A.size(), ans = 0, last_pos = 0, count_one = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            if (A[i] == 1 && i - last_pos < K) {
                dp[i] += dp[]
            }
        }
        return dp[n-1];
    }
};
int main() {
    
}