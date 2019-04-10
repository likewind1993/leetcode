#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        int n = people.size();
        vector<int>weight(n);
        vector<int>dp(n);

        for (int i = 1; i < n; i++) {
            
        }
        return 0;
    }
};
int main() {
    vector<int> people = { 3,2,2,1 };
    Solution solution;

    cout<<solution.numRescueBoats(people, 4);

    return 0;
}