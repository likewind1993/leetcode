#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A)
    {
        vector<int> negative_nums;
        vector<int> res;
        int p = 0;

        while (p < A.size()) {
            if(A[p] < 0)
                negative_nums.push_back(-A[p]);
            else if(A[p] >= 0)
                break;
            ++p;
        }
        int q = negative_nums.size()-1;
        while (p < A.size()&& q >= 0) {
            if (A[p] < negative_nums[q]) {
                res.push_back(pow(A[p], 2));
                ++p;
            }
            else {
                res.push_back(pow(negative_nums[q], 2));
                --q;
            }
        }
        while (p < A.size()) {
            res.push_back(pow(A[p], 2));
            ++p;
        }
        while (q >=0) {
            res.push_back(pow(negative_nums[q], 2));
            --q;
        }
        return res;
    }
};

int main() {
    vector<int> A = { -1 };
    Solution solution;
    vector<int> res = solution.sortedSquares(A);
    for(auto iter : res)
        cout<<iter<<endl;
    return 0;
}