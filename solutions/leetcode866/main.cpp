/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int GetTreeDepth(TreeNode * root) {
        if(root == NULL)
            return 0;
        int left_depth = GetTreeDepth(root->left);
        int right_depth = GetTreeDepth(root->right);

        return max(left_depth, right_depth);
    }

    void visit_tree(TreeNode * root, int depth, int cur_depth, vector<TreeNode*>&ans)
    {
        

        if (root == NULL) return;
        if (cur_depth == depth)
            ans.push_back(root);
        visit_tree(root->left, depth, cur_depth + 1, ans);
        visit_tree(root->right, depth, cur_depth + 1, ans);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        int depth = GetTreeDepth(root);
        vector<TreeNode*> ans;
        visit_tree(root, depth, 0, ans);

        for(int i = 0; i<ans.size(); i++)
            cout<<ans[i]->val<<" ";
        return NULL;
    }
    TreeNode * createNode(int val)
    {
        TreeNode * node = new TreeNode(val);
        return node;
    }

    TreeNode * createTree()
    {
        int val = 0;
        cin >> val;
        if (val == -1) return NULL;

        TreeNode * root = new TreeNode(val);
        root->left = createTree();
        root->right = createTree();

        return root;
    }
    
};
int main()
{
    //3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1
    Solution solution;
    TreeNode * root = solution.createTree();
    solution.subtreeWithAllDeepest(root);

    return 0;

}