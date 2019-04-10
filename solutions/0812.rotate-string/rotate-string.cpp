#include <iostream>
#include <string>
using namespace std;
class Solution {

    bool judge(string b, string temp) {
        int n = b.size(), m = temp.size();
        for(int i = 0; i<m; i++){
            if(b[n-m + i] != temp[i])
                return false;
        }
        return true;
    }
public:
    bool rotateString(string A, string B)
    {
        int n = A.size(), m = B.size();
        if (m != n) return false;
        string temp = "";
        int i = 0, j = 0, flag = 0;
        while (i<n && j<m) {
            if (A[i] != B[j]) {
                temp += A[i];
                i++;
                continue;
            }
            else {
                if (judge(B, temp)) {
                    flag = 1;
                    break;
                }
                temp+=A[i];
                i++;
                continue;   
            }
        }
        if(i == n) return false;
        if (flag = 1) {
            for (int i = temp.size(); i < n; i++) {
                if(A[i] != B[i-temp.size()])
                    return false;
            }
        }
        return true;
    }
};