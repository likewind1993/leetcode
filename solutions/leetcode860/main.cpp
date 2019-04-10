#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int count_five = 0, count_ten = 0, n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                count_five += 1;
            }
            else if (bills[i] == 10) {
                if(count_five<1)
                    return false;
                count_five -= 1;
                count_ten += 1;
            }
            else if (bills[i] == 20) {
                if (count_ten >= 1 && count_five >= 1) {
                    count_ten -= 1;
                    count_five -= 1;
                }
                else if (count_five >= 3) {
                    count_five -= 3;
                }
                else 
                    return false;
            }
        }
        return true;
    }
};
int main() {
    vector<int> bills = { 5,5,10,10,20 };
    Solution solution;
    if(solution.lemonadeChange(bills))
        cout<<"True"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}