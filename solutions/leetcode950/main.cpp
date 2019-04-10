#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck)
    {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        if(n <= 2)
            return deck;
        vector<int> res(2 * n - 2);
        int biggest = n-3, temp_ptr = 2 * n - 2 -1;
        int last = 2 * n - 2 - 1;
        res[temp_ptr--] = deck[n-1];
        res[temp_ptr--] = deck[n-2];
        
        for (int i = temp_ptr; i >= 0; --i) {
            
            res[i--] = res[last--];
            res[i] = deck[biggest--];
        }
        res.erase(res.begin() + n, res.end());

        return res;

    }
};

int main() {
    vector<int> deck = { 3, 2 };

    Solution solution;
    vector<int> res = solution.deckRevealedIncreasing(deck);

    for(auto iter : res)
        cout<<iter<<endl;

    return 0;
    
}