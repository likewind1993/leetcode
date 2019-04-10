#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        int n = s.size();
        if(n == 0 || numRows == 1)
            return s;
        int cols = (numRows - 1) * (n / ( 2 * numRows - 2 ) + 1);

        vector<vector<char>> graph(numRows,vector<char>(cols, '\0'));

        int i = 0, j = 0, p = 0;
        bool is_second = false;
        while(p<s.size()) {
            graph[i][j] = s[p];
            if ( !is_second ) {
                ++i;
            }else {
                --i;
                ++j;
            }  
            if(i == numRows) {
                is_second = true;
                i-=2;
                ++j;
            }
            if(i == 0) {
                is_second = false;
            }
            p++;
        }
        string ans = "";
        for(i = 0; i<numRows; ++i) {
            for(j = 0; j<cols; ++j)
                if(graph[i][j] != '\0')
                    ans += graph[i][j];
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout<<solution.convert("LEETCODEISHIRING", 2)<<endl;

    return 0;
}