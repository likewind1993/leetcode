#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<int> diStringMatch(string S)
    {
        int n = S.size(), min_ = 0, max_ = 0;
        vector<int> res(n+1);
        res[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (S[i] == 'I') {
                res[i+1] = max_ + 1;
                max_ = res[i+1];
            }
            else if (S[i] == 'D') {
                res[i+1] = min_ - 1;
                min_ = res[i+1];
            }
        }

        int increase = abs(min_);
        for (int i = 0; i <= n; ++i) {
            res[i] += increase;
        }
        return res;

    }
};
int main() {
    string str = "DDI";

    Solution solution;

    vector<int> res = solution.diStringMatch(str);

    for(auto iter : res)
        cout<<iter <<endl;

    return 0;
}
