#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words)
    {
        int n = S.size();
        int count = 0;
        vector<set<int>>chars(26);
        for(int i = 0; i<n; i++)
            chars[S[i] - 'a'].insert(i);
        for (int i = 0; i < words.size(); i++) {
            int p = 0; 
            bool found = true;
            for (int j = 0; j < words[i].size(); j++) {
                int c = words[i][j] - 'a';
                auto iter = chars[c].lower_bound(p);
                if(iter != chars[c].end())
                    p = *iter + 1;
                else{
                    found = false;
                    break;
                }
            }
            if(found)
                count++;
        }
        return count;
    }
};
