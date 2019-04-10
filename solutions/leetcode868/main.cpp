#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A)
    {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = A[i][j];
            }
        }
        return ans;
    }
};

void print(vector<vector<int>> A)
{
    int m = A.size();
    int n = A[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------"<<endl;
}

int main() {
    vector<vector<int>> A = { {1,2,3},{4,5,6} };

    print(A);

    Solution solution;
    vector<vector<int>> a = solution.transpose(A);
    print(a);
    return 0;
}