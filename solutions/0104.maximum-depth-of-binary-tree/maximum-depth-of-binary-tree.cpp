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
    int maxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        
        int leftchild_depth = maxDepth(root->left)+1;
        int rightchild_depth = maxDepth(root->right)+1;

        return leftchild_depth>=rightchild_depth ? leftchild_depth : rightchild_depth;
    }
};
