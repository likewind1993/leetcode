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
    void findBottomLeftValue(TreeNode * root, int& max_level, int& left_val, int depth)
    {
        if (root == NULL) return;

        findBottomLeftValue(root->left, max_level, left_val, depth + 1);
        findBottomLeftValue(root->right, max_level, left_val, depth + 1);
        
        if (depth > max_level)
        {
            max_level = depth;
            left_val = root->val;
        }
    }

    int findBottomLeftValue(TreeNode* root)
    {
        int max_level = 0, left_val = root->val;
        findBottomLeftValue(root, max_level, left_val, 0);
        
        return left_val;
    }
};