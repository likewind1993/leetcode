#include <iostream>

using namespace std;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000


class Solution {
public:
    int myAtoi(string str)
    {
        int n = str.size(), ans = 0, j = 0, count = 0, int_min = INT_MIN;
        int * chars = static_cast<int *>(malloc(n * sizeof(int)));
        bool is_positive = true, is_num = true;
        for(int i = 0; i<n; ++i) {
            if(str[i] == ' ')
                continue;
            if(str[i] == '+' || str[i] == '-') {
                is_positive = str[i] == '+';
                if(i<n-1 && !(str[i+1] >= '0' && str[i+1] <= '9'))
                    break;
                continue;
            }
            if(str[i]>='0' && str[i]<='9') {
                chars[j++] = str[i] - '0';
                if( i<n-1 && (str[i+1] >'9' || str[i+1] <'0' ))
                    break;
                continue;
            }
            break;
        }
        long long temp = 0;
        if(j > 11)
            return !is_positive ? int_min : INT_MAX;
        count = j;
        j--;
        
        for(int i = 0; i<count; ++i) {
            temp += chars[i] * pow(10, j--);
            if (!is_positive && (-1 * temp) <= int_min)
                return int_min;
            if(temp > INT_MAX )
                return INT_MAX;
            
        }
        if(!is_positive)
            temp = -1 * temp;
        return temp;
    }
};

int main()
{
    string str = "20000000000000000000";
    Solution solution;
    cout<<solution.myAtoi(str)<<endl;
    return 0;
}