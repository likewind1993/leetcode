#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    void swap(string& str, int pos1, int pos2) {
        int temp = str[pos1];
        str[pos1] = str[pos2];
        str[pos2] = temp;
    }
    bool buddyStrings(string A, string B)
    {
        int n = A.size(), m = B.size();
        int count[26];
        for(int i = 0; i<26; i++)
            count[i] = 0;
        if (n != m || n < 2 || m<2)
            return false;
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (A[i] != B[i]) 
                pos.push_back(i);
            else
                count[A[i] - 'a']++;
        }
        if (pos.size() > 2 || pos.size() == 1) 
            return false;
        if (pos.size() != 0) 
            swap(A, pos[0], pos[1]);
        else {
            for(int i = 0; i<26; i++)
                if(count[i] >= 2)
                    return true;
            return false;
        }
        
        if(A != B)
            return false;

        return true;
    }
};