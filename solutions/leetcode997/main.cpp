#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust)
    {
      
        int n = trust.size();
        if (n == 0) {
            return N;
        }
        int m = trust[0].size();
        vector<vector<int>> vote(N, vector<int>(N, 0));

        for (int i = 0; i < n; ++i) {
            int a = trust[i][0], b = trust[i][1];
            vote[a-1][b-1] = 1;
        }
        vector<int> judges;
        for (int i = 0; i < N; ++i) {
            int sum = 0;
            for (int j = 0; j < N; ++j) {
                sum += vote[j][i];
            }
            if(sum == N-1)
                judges.emplace_back(i);
        }
        for (int i = 0; i < judges.size(); ++i) {
            int candidate = judges[i];
            int sum = 0;
            for (int j = 0; j < N; ++j) {
                sum += vote[candidate][j];
            }
            if(sum == 0)
                return candidate + 1;
        
        }
        return -1;
    }
};
//example:
//vector<vector<int>> trust = { {1, 3},{1, 4},{2, 3}, {2, 4}, {4, 3}};
int main() {
    Solution solution;
    vector<vector<int>> trust = {};


    cout<<solution.findJudge(1, trust)<<endl;

    return 0;

}