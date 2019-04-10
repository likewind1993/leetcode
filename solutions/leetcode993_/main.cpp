#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode * createTree()
{
    int val = 0;
    cin >> val;
    TreeNode * root = NULL;
    if (val != -1)
    {
        root = new TreeNode(val);
        root->left = createTree();
        root->right = createTree();
    }

    return root;
}
void printTree(TreeNode * root)
{
    if (root == NULL)
        return;
    cout << root->val << endl;
    printTree(root->left);
    printTree(root->right);
}
class Solution {
public:
    void visit_tree(TreeNode * root, int x, int y, int cur_depth, int &depth_x, int &depth_y, int &parent_x, int &parent_y){
        if(root == NULL)
            return ;
        else{
            if(root->val == x)
                depth_x = cur_depth;
            if(root->val == y)
                depth_y = cur_depth;
            if (root->left != NULL){
                if(root->left->val == x)
                    parent_x = root->val;
                else if(root->left->val == y)
                    parent_y = root->val;
            }
            if(root->right != NULL){
                if(root->right->val == x)
                    parent_x = root->val;
                else if(root->right->val == y)
                    parent_y = root->val;
            
            }

            visit_tree(root->left, x, y, cur_depth+1, depth_x, depth_y, parent_x, parent_y);
            visit_tree(root->right, x, y, cur_depth+1, depth_x, depth_y, parent_x, parent_y);
        }
    
    }

    bool isCousins(TreeNode* root, int x, int y)
    {
        int depth_x = 0, depth_y = 0;
        int parent_x = -1, parent_y = -1;

        visit_tree(root, x, y, 0, depth_x, depth_y, parent_x, parent_y);

        if(depth_x == depth_y && parent_x != parent_y)
            return true;

        return false;
    }
};


//[1,18,2,null,null,3,4,17,10,5,6,null,null,21,12,8,11,31,7,null,null,37,15,null,9,29,14,null,35,24,20,44,null,19,25,22,13,41,32,39,16,36,null,null,null,27,null,null,null,23,null,null,47,30,26,null,49,null,50,null,null,null,null,45,28,null,null,null,null,43,null,null,null,34,38,null,33,null,null,null,null,null,46,40,null,null,null,null,48,null,42]
//28
//30
int main() {
    TreeNode * root = createTree();
    Solution solution;
    cout<<solution.isCousins(root, 2, 3)<<endl;


    return 0;
}
