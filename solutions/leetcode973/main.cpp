#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Point {
public:
    int x;
    int y;

    bool operator < (const Point &p) const {
        int distance1 = sqrt(pow(x, 2) + pow(y, 2));
        int distance2 = sqrt(pow(p.x, 2) + pow(p.y, 2));


        return distance1<distance2;
    }

};

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        vector<Point> temp;
        for (auto point : points) {
            Point tem;
            tem.x = point[0];
            tem.y = point[1];
            temp.push_back(tem);
        }
        
        sort(temp.begin(), temp.end());



        vector<vector<int>> res;
        for (int i = 0; i < K; ++i) {
            res.push_back(vector<int>(temp[i].x, temp[i].y));
        }
        return res;
    }
};

//[[-5,4],[-6,-5],[4,6]]
//2


int main() {
    vector<vector<int>> input = { {-5, 4}, {-6, -5}, {4, 6} };
    Solution solution;

    solution.kClosest(input, 2);


    return 0;
}