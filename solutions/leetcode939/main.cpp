#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:

    //code ref:
    //https://leetcode.com/problems/minimum-area-rectangle/discuss/192026/C%2B%2B-hash-map-%2B-set-intersection-56-ms
    int minAreaRect(vector<vector<int>>& points)
    {
        int res = INT_MAX;
        unordered_map<int, set<int>> x;
        for (auto p : points) x[p[0]].insert(p[1]);

        for (auto i = x.begin(); i != x.end(); ++i) {
            if(i->second.size() < 2) continue;

            for (auto j = next(i); j != x.end(); ++j) {
                if (j->second.size() < 2) continue;

                vector<int> y;

                set_intersection(begin(i->second), end(i->second),
                                 begin(j->second), end(j->second),
                                 inserter(y,y.begin()));

                for (int k = 1; k<y.size(); ++k){
                    res = min(res, abs(j->first - i->first) * (y[k] - y[k-1]));
                
                }
            }
            
        }
        return res == INT_MAX ? 0 : res;
    }
};
//test example
//vector<vector<int>> points = { {1,1},{1,3},{3,1},{3,3},{2,2} };
//vector<vector<int>> points = { {1, 1},{1, 3},{3, 1}, {3, 3},{4, 1},{4, 3} };

int main() {
    Solution solution ;

    vector<vector<int>> points = { {1, 1},{1, 3},{3, 1}, {3, 3},{4, 1},{4, 3} };

    cout<<solution.minAreaRect(points)<<endl;

    return 0;
}



