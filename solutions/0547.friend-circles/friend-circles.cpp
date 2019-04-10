class Solution {
private:
    
    int find(int * par, int x) { return par[x] == x ? x : (par[x] = find(par, par[x])); }
    
    bool same(int * par, int x, int y) { return par[x] == par[y]; }
    
    void unit(int * par, int x, int y)
    {
        x = find(par, x);
        y = find(par, y);
        if (x == y) return;

        par[y] = x;
    }
public:

    int findCircleNum(vector<vector<int>>& M)
    {
        int num_students = M[0].size();
        int * pre = new int[num_students];
        for (int i = 0; i < num_students; i++) pre[i] = i;

        for (int i = 0; i < num_students; i++)
        {
            for (int j = i+1; j < num_students; j++)
            {
                if (M[i][j] == 1 && !same(pre, i, j))
                    unit(pre, i, j);
            }
        }
        set<int> circles;
        for (int i = num_students - 1; i >= 0; --i)
        {
            int j = i;
            while (pre[j] != j)
                j = pre[j];
            circles.insert(j);
        }
        return circles.size();
    }
};