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
    TreeNode * createTree()
    {
        TreeNode * root = NULL;
        int val = 0;
        cin >> val;

        if (val != -1)
        {
            root = new TreeNode(val);
            root->left = createTree();
            root->right = createTree();
        }
        return root;
    }
    int minDepth(TreeNode* root)
    {
        if (root == NULL) return 0;

        int leftchild_depth = minDepth(root->left);
        int rightchild_depth = minDepth(root->right);
        
        return 1 + ((min(leftchild_depth, rightchild_depth) ? min(leftchild_depth, rightchild_depth) : max(leftchild_depth, rightchild_depth)));
    }
};