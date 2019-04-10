#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxWidthRamp(vector<int>& A)
    {
        int n = A.size();
        int min_index = 0, min_val = A[0], res = 0;
        vector<int> dp(n);

        for (int i = 1; i < n; ++i) {
            if (min_val <= A[i]) {
                if (res < i - min_index) {
                    res = i - min_index;
                  
                }
            } 
        
        
        }
        return dp[n];
    }
};
int main() {
    vector<int> A = { 9,8,1,0,1,9,4,0,4,1 };
    Solution solution;

    cout<<solution.maxWidthRamp(A)<<endl;

    return 0;
    
}