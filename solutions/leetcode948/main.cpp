#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P)
    {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int ans = 0, cur_p = 0, point = 0;
        while (cur_p < n) {
            while (cur_p < n && tokens[cur_p] <= P) {
                P = P - tokens[cur_p];
                ans++;
                point++;
                cur_p++;
            }
            while (cur_p < n && P<tokens[cur_p]) {
                if (point == 0){
                    cur_p++;
                    break;
                }
                else
                {
                    P = P + tokens[cur_p];
                    point--;
                    cur_p++;
                }
                
            }
        }
        return ans;
    }
};
//examples
//100, 50
//100, 200, 150
//100, 200, 300, 400, 200
//81, 91, 31, 73
int main() {
    vector<int> tokens = { 81, 91, 31 };
    Solution solution;

    cout<<solution.bagOfTokensScore(tokens, 73)<<endl;

    return 0;
        
}