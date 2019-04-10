#include <vector>
#define max(a, b) (a > b ? a : b)
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& a, int k)
    {
        int n = a.size();
        double mem[n][k + 1];
        for (int i = 0; i < n; ++i) for (int j = 0; j <= k; ++j) mem[i][j] = -1.0;
        mem[0][1] = a[0] / 1.0;
        for (int i = 1; i < n; ++i)
        {
            double s = a[i];
            for (int j = i; j-- > 0; )
            {
                for (int u = 0; u < k; ++u) 
                    if (mem[j][u] > -0.1)
                    {
                        mem[i][u + 1] = max(mem[i][u + 1], mem[j][u] + s / (i - j));
                    }
                s += a[j];
            }
            mem[i][1] = max(mem[i][1], s / (i + 1));
        }
        double ret = 0.0;
        for (int i = 1; i <= k; ++i) ret = max(ret, mem[n - 1][i]);
        return ret;
    }
};