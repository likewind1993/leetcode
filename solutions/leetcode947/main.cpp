#include <vector>
#include <iostream>
#include <set>
using namespace std;

class DSU
{
private:
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        for(int i = 0; i<n; ++i)
            parent[i] = i;
    };
    ~DSU() = default;
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool same_component(int x, int y) {
        return find(x) == find(y) ? true:false;
    }
    void union_(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();
        DSU dsu(20000);

        for (const auto& stone : stones) {
            dsu.union_(stone[0], stone[1]+10000);
        }
        set<int> seen;
        for (const auto& stone : stones) {
            seen.insert(dsu.find(stone[0]));
        }
        return n-seen.size();
    }
};
//examples:
//{ {0, 0},{0, 1},{1, 0},{1,2},{2,1},{2,2} }
//{{0, 0}}
//{{0, 0},{0, 2}, {1, 1}, {2, 0}, {2, 2}}
int main() {
    vector<vector<int>> stones = { { 0, 0 },{ 0, 2 },{ 1, 1 },{ 2, 0 },{ 2, 2 } };

    Solution solution;
    cout<<solution.removeStones(stones)<<endl;
    return 0;
}