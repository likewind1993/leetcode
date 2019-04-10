#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool validMountainArray(vector<int>& A)
    {
        int n = A.size(), chang_count = 0;
        bool up = true;
        if(n < 3) return false; 
        if(!(A[0]<A[1])) return false;

        for (int i = 0; i < n-1; ++i) {
            if (A[i] < A[i + 1])
                if (!up) {
                    up = true;
                    chang_count++;
                }
            if(A[i]>A[i+1])
                if (up) {
                    up = false;
                    chang_count++;
                }
            if(A[i] == A[i+1])
                return false;
        }
        return !up &&(chang_count == 1) ? true : false;
    }
};

int main()
{
    vector<int> nums = { 3,3,2,1,-1 };
    Solution solution;
    cout<<solution.validMountainArray(nums)<<endl;

    return 0;
}