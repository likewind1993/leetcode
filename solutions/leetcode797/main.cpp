#include <iostream>
#include <vector>
using namespace std;
class Solution {
    void init(vector<int>&path, vector<int>&visited, int n) {
        for (int i = 0; i < n; i++) {
            path[i] = -1; 
            visited[i] = false;
        }
    }
    void dfs(vector<vector<int>>&graph, vector<int>&path, vector<int>&visited, int cur) {
        for (int i = 0; i < graph[cur].size; i++) {
            if(i = graph.size() - 1)
                return;
            if (visited[i] == false) {
                path[i] = cur;
                dfs(graph, path, visited, i);
            }
            visited[i] = true;
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> path(n);
        vector<int> visited(n);
        init(path, visited, n);
        int source = 0, dest = n-1;
        for (int i = 0; i < graph[source].size(); i++) {
            int cur = graph[source][i];
            path
            dfs(graph, path, visited, cur);
        }
    }
};