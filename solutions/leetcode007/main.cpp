#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

// ִ����ʱ : 8 ms, ��Reverse Integer��C++�ύ�л�����99.57% ���û�
// �ڴ����� : 8 MB, ��Reverse Integer��C++�ύ�л�����0.67% ���û�
//class Solution {
//public:
//    int reverse(int x)
//    {
//        int res{ 0 };
//        while (x)
//        {
//            auto temp{ x % 10 };
//            x /= 10;
//            if ((temp > 0 && (INT_MAX - temp) / 10 < res) || (temp < 0 && (INT_MIN - temp) / 10 > res))
//                return 0;
//            res = res * 10 + temp;
//        }
//        return res;
//    }
//};

class Solution {
public:
    int reverse(int x)
    {
        int chars [32], i = 0;
        long long x_positive = 0, ans = 0;
        bool is_positive = false;
        if(x >=0 )
            is_positive = true;
        x_positive = x;
        x_positive = abs(x_positive);
        while(x_positive) {
            chars[i++] = x_positive % 10;
            x_positive = x_positive / 10;
        }
        --i;
        for(int j = 0; i>=0; --i, ++j) {
            ans += pow(10, i) * chars[j];
        }
        if(ans > 0x7fffffff)
            return 0;
        if(!is_positive)
            ans = ans * -1;
        return ans;
    }
};
//example
//-2147483647
//-2147483648
int main()
{
    Solution solution;
    cout<<solution.reverse(-2147483648)<<endl;
    
    return 0;
}