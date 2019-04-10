#include <cmath>
#include <iostream>
#include <vector>
#define MAX(a, b) (a > b ? a : b)
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points)
    {
        double ans = 0;
        for (size_t i = 0; i < points.size(); ++i) {
            for (size_t j = i + 1; j < points.size(); ++j) {
                for (size_t k = j + 1; k < points.size(); ++k)
                {
                    double a = sqrt(pow((points[j][0] - points[i][0]), 2) + pow((points[j][1] - points[i][1]), 2));
                    double b = sqrt(pow((points[k][0] - points[j][0]), 2) + pow((points[k][1] - points[j][1]), 2));
                    double c = sqrt(pow((points[k][0] - points[i][0]), 2) + pow((points[k][1] - points[i][1]), 2));
                    if((a+b)<c || (a + c) < b || (b + c) < a)
                        continue;

                    double p = (a+b+c) / 2;
                    ans = MAX(ans, sqrt((p*(p-a)*(p-b)*(p-c))));
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>>Points = { { -35, 19 },{ 40, 19 }, { 27, -20 },{ 35, -3 },{ 44, 20 }, {22, -21}, {35, 33},{-19, 42}, {11, 47}, {11, 37} };
    Solution solution;
    cout<<solution.largestTriangleArea(Points)<<endl;

    return 0;
}