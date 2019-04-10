#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> res;
        int n = S.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i - j) >= 0 && S[i-j] == C) {
                    res.push_back(j);
                    break;
                }
                if ((i + j) <n && S[i + j] == C) {
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};