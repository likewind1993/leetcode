#include <vector>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        vector<int> res;
        set<int> set_res;
        for (int i = 0; pow(x, i) <= bound; ++i) {
            for (int j = 0; pow(y, j) <= bound; ++j) {
                int sum = pow(x, i) + pow(y, j);

                if(sum <= bound)
                    set_res.insert(sum);
                if(y == 1)
                    break;
            }
            if(x == 1)
                break;
        }

        for(auto iter : set_res)
            res.push_back(iter);
        return res;
    }
};

int main() {
    
    Solution solution;

    vector<int>res = solution.powerfulIntegers(2, 1, 100);

    for(auto iter : res)
        cout<<iter<<endl;

    return 0;

}