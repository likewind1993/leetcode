class Solution {
public:
    void get_all_combins(vector<vector<int>>& ans, vector<int>& can, vector<int> temp , int target, int sum, int index)
    {
        if(sum == target) {
            ans.push_back(temp);
            return ;
        }
        for(int i = index; i<can.size(); ++i) {
            if(sum + can[i] > target) {
                return;
            }
                
            temp.push_back(can[i]);
            get_all_combins(ans, can, temp, target, sum + can[i], i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        get_all_combins(ans, candidates, temp, target, 0, 0);
        
        return ans;
    }
    
};