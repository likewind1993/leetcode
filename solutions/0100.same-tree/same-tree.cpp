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

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p != NULL && q != NULL && p->val == q->val)
            return (isSameTree(p->left, q->left) && (isSameTree(p->right, q->right)));
        else 
            return false;
    }
};