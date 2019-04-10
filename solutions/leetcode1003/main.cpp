#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int find_abc(string S) {
        for (int i = 0; i <= S.size()-3; ++i) {
            if (S[i] == 'a' && S[i+1] == 'b' && S[i+2] == 'c') {
                return i;
            }
        }
        return -1;
    }
    bool isValid(string S)
    {
        while (true) {
            int index = find_abc(S);
            if(index == -1)
                return true;
        }
        
        
    }
};


int main() {
    string a = "abc";

    //a.erase(a.begin(), 1);
    //a.erase(0);
    //a.erase(0);
    
    cout<<a<<endl;

    return 0;

}