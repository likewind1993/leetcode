class Solution {
public:

    void get_all_combins(vector<vector<int>>& ans, vector<int>& cans, 
        vector<bool>& is_visited, vector<int> temp, int target, int sum, int index)
    {
        if(sum == target) {
            ans.push_back(temp);
            return ;
        }
        for(int i = index; i<cans.size(); ++i) {
            if(i != 0 && cans[i] == cans[i-1] && !is_visited[i-1])
                continue;
            if(!is_visited[i] && cans[i] + sum <= target) {
                is_visited[i] = true;
                temp.push_back(cans[i]);
                get_all_combins(ans, cans, is_visited, temp, target, sum + cans[i], i);
                is_visited[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> is_visited(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        get_all_combins(ans, candidates, is_visited, temp, target, 0, 0);
        return ans;
    }
};
