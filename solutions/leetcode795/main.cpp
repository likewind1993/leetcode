#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R)
    {
        int n = A.size();
        vector<int>dp(n);
        for (int i = 0; i < n; i++)
            if (A[i] >= L && A[i] <= R)
                dp[i] = 1;
        for (int i = 1; i < n; i++) {
            if( A[i-1] + 1 == A[i] || A[i-1] - 1 == A[i] )
                dp[i] = dp[i-1] + 1;
            else
                dp[i] = dp[i-1];
        }
        return dp[n-1];
    }
};

int main()
{
    vector<int> A = { 2, 9, 2, 5, 6 };
    Solution solution;
    cout<<solution.numSubarrayBoundedMax(A, 2, 8)<<endl;
    return 0;
}