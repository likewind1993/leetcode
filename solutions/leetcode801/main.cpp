//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//class Solution {
//public:
//    int minSwap(vector<int>& A, vector<int>& B)
//    {
//        int n = A.size();
//        vector<int>dp(n);
//        dp[0] = 0;
//        for (int i = 1; i < n; i++) {
//            if (A[i-1] >= A[i] || B[i-1] >= B[i]) {
//                int temp = A[i-1];
//                A[i-1] = B[i-1];
//                B[i-1] = temp;
//                dp[i] = dp[i-1] + 1;
//            }else
//                dp[i] = dp[i-1];
//        }
//        return dp[n-1];
//    }
//};
//
//int main() {
//    vector<int> A = { 3, 3, 8, 9, 10 }, B = { 1, 7, 4, 6, 8 };
//    Solution solution;
//    cout<<solution.minSwap(A, B)<<endl;
//
//    return 0;
//}
#include <stdio.h>

int main()
{
    int b = 10086;
    int * a = &b;   
    int ** c = &a;
    printf("%d\n", **c);

    return 0;
}