#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A)
    {
        string res("");
        sort(A.begin(), A.end());
        vector<int> digits;
        for (int t = 0; t < 1440; ++t)
        {
            int sec = t % 60;

            
            digits.push_back(sec % 10);
            digits.push_back(sec / 10);

            int hours = t / 60;
            hours = hours % 24;
            digits.push_back(hours % 10);
            digits.push_back(hours / 10);

            sort(digits.begin(), digits.end());

            if (A == digits) {
                char str[6];
                sprintf(str, "%d%d:%02d", hours/10, hours % 10, sec);
                res = str;
                cout<<res<<endl;
            }
        }
        return res;
    }
};

int main() {
    
    Solution solution;
    vector<int> A = { 9, 0, 1, 3};
    cout<<solution.largestTimeFromDigits(A)<<endl;

    return 0;
    
}