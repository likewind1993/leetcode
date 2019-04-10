#include <iostream>
#include <vector>

using namespace std;
//Code Ref:https://leetcode.com/problems/redundant-connection-ii/discuss/108045/C%2B%2BJava-Union-Find-with-explanation-O(n)
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge : edges)
        {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0];
            else
            {
                candA = { parent[edge[1]], edge[1] };
                candB = edge;
                edge[1] = 0;
            }
        }
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge : edges)
        {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1], pu = root(parent, u);
            // Now every node only has 1 parent, so root of v is implicitly v
            if (pu == v)
            {
                if (candA.empty()) return edge;
                return candA;
            }
            parent[v] = pu;
        }
        return candB;
    }
private:
    int root(vector<int>& parent, int k)
    {
        if (parent[k] != k)
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};




class DSU
{
public:
    DSU(int n) {
        m_parent.resize(n);
        for(int i = 0; i<n; ++i) m_parent[i] = i;
    };
    ~DSU() = default;
    int find(int x) {
        if(m_parent[x] != x)
            m_parent[x] = find(m_parent[x]);
        return m_parent[x];
    }
    void union_(int x, int y) {
        if(find(x) != find(y))
            m_parent[find(x)] = find(y);
    }
    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> m_parent;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int> res;
        DSU dsu(n+1);
        for (const auto& iter : edges) {
            if (!dsu.isSameComponent(iter[0], iter[1])) {
                dsu.union_(iter[0], iter[1]);
            }
            else {
                if (!res.empty()) {
                    res.pop_back();
                    res.pop_back();
                }
                if (iter[0] < iter[1]) {
                    res.push_back(iter[0]);
                    res.push_back(iter[1]);
                }
                else {
                    res.push_back(iter[1]);
                    res.push_back(iter[0]);
                }
            }
        }

        return res;
    }
};

//examples:
//{{1,2}, {1,3}, {2,3}}
//{{1,2}, {2,3}, {3,4}, {1,4},  {1,5}}
int main() {
    vector<vector<int>> edges = { { 1,2 },{ 2,3 },{ 3,4 },{ 1,4 },{ 1,5 } };
    Solution solution;

    for(auto iter : solution.findRedundantConnection(edges)){
        cout<<iter<<endl;
    }
    return 0;
}