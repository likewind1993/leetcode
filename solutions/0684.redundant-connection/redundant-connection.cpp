#include <iostream>
#include <vector>

using namespace std;

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