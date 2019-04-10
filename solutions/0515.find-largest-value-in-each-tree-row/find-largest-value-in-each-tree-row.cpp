/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void largestValues(TreeNode* root, map<int, int>& count, bool* visited, int depth)
    {
        if (root == NULL) return;

        largestValues(root->left, count, visited, depth + 1);
        largestValues(root->right, count, visited, depth + 1);

        if (root->val > count[depth] && visited[depth] == true)
            count[depth] = root->val;
        if (visited[depth] == false)
        {
            count[depth] = root->val;
            visited[depth] = true;
        }
            

    }
    vector<int> largestValues(TreeNode* root)
    {
        map<int, int> count;
        vector<int> result;
        bool visited[1000];

        for (int i = 0; i < 1000; i++) visited[i] = false;

        if (root == NULL) return result;
        
        largestValues(root, count, visited, 0);
        
        for (auto iter : count) { result.push_back(iter.second); }
        
        return result;
    }
};