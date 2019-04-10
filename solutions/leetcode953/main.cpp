#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> order_map;

    bool isAlienSorted(vector<string>& words, string order)
    {
        
        for(int i = 0; i<order.size(); ++i)
            order_map.insert(make_pair(order[i], i));
        int index = 0, n = words.size();
        
        int flag = true, cur_iter = true;
        for (int i = 0; i < 20; ++i) {
            cur_iter = true;
            for (int j = 0; j < words.size()-1; ++j) {
                int a = -1, b = -1;
                if(i < words[j].size())
                    a = order_map[words[j][i]];
                if(i < words[j+1].size())
                    b = order_map[words[j+1][i]];
                if (a > b) {
                    flag = false;
                    cur_iter = true;
                    break;
                }
                else if (a == b) {
                    cur_iter = false;
                }
                    
            }
            if(cur_iter)
                break;
    
        }


        return flag;
    }
};

int main() {
    Solution solution;
    string order = "abcdefghijklmnopqrstuvwxyz";
    vector<string> words = { "apple","app" };
    cout<<solution.isAlienSorted(words, order)<<endl;

    return 0;
}