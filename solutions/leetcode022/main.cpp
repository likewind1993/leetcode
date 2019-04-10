#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void genPars(vector<string> &res, string str, int n, int left_par, int right_par, int cur)
    {
        if(cur == n-1) {
            res.push_back(str + ')');
            return ;
        }
        if (left_par == right_par)
        {
            str += '(';
            genPars(res, str, n, left_par + 1, right_par, cur + 1);
        }else {
            if(left_par < n / 2) {
                genPars(res, str + '(', n, left_par + 1, right_par, cur + 1);
                genPars(res, str + ')', n, left_par, right_par + 1, cur + 1);
            }else {
                genPars(res, str + ')', n, left_par, right_par + 1, cur + 1);
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        if(n == 0)
            return ans;
        genPars(ans, "", n*2, 0, 0, 0);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = solution.generateParenthesis(0);
    for (auto str : strs) {
        cout<<str<<endl;
    }
    return 0;
}