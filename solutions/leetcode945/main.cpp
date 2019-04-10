#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A)
    {
        int n = A.size();
        vector<int> dp(n);
        dp[0] = 0;
        sort(A.begin(), A.end());
        int last_val = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] > last_val) {
                dp[i] = dp[i - 1];
                last_val = A[i];
            }
            else {
                
                dp[i] = dp[i-1] + (last_val - A[i] + 1);
                last_val = last_val + 1;
            }
        }
        return dp[n-1];
    }
};


//examples:
//1,2,2
//3,2,1,2,1,7
int main() {
    vector<int> A = { 3,2,1,2,1,7 };
    Solution solution;
    cout<<solution.minIncrementForUnique(A)<<endl;

    return 0;
    
}