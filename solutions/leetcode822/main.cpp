#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int exchange_num(vector<int>& fronts, vector<int>& backs, int pos) {
        int temp = fronts[pos];
        fronts[pos] = backs[pos];
        backs[pos] = temp;
        return temp;
    }
    int flipgame(vector<int>& fronts, vector<int>& backs)
    {
        set<int> result;
        int n = fronts.size();
        for (int i = 0; i < n; i++) {
            if(fronts[i] == backs[i])
                continue;
            int num = exchange_num(fronts, backs, i);
            vector<int>::iterator res = find(fronts.begin(), fronts.end(), num );
            if (res == fronts.end()) {
                result.insert(num);
            }
            exchange_num(fronts, backs, i);
            
        }
        if(result.empty())
            return 0;
        return *result.begin();
    }
};

int main() {
    Solution solution;
    vector<int> fronts = { 1,1 };
    vector<int> backs = { 1,2 };
    cout<<solution.flipgame(fronts, backs)<<endl;
    return 0;
}