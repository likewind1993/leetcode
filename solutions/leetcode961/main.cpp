#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A)
    {
        vector<int> flag(10001) ;
        int res = -1;
        for (int i = 0; i < A.size(); ++i) {
            if(flag[A[i]] == 0)
                flag[A[i]]++;
            else {
                res = A[i];
                break;
            }
        }
        return res;

    }
};
int main() {
    vector<int> A = { 5,1,5,2,5,3,5,4};
    Solution solution;
    cout<<solution.repeatedNTimes(A)<<endl;


    return 0;
}