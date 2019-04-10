#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
class Solution {
   
public:
    int minDeletionSize(vector<string>& A)
    {
        int n = A.size(), m = A[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n-1; ++j) {
                if (A[j][i] > A[j + 1][i]) {
                    res += 1;
                    break;        
                }
            }
        }
        return res;

    }
};

int main() {
    Solution solution;
    vector<string> args = { "zyx","wvu","tsr" };
    cout<<solution.minDeletionSize(args)<<endl;

    return 0;
}