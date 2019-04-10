#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
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

    void swapSubTree(TreeNode * root) {
        TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        if (root1 != NULL && root2 != NULL) {
            if (root1->val != root2->val)
                return false;

            int root1_left_val = -1, root1_right_val = -1, root2_left_val = -1, root2_right_val = -1;
            if (root1->left != NULL)
            {
                root1_left_val = root1->left->val;
            }
            if (root1->right != NULL)
            {
                root1_right_val = root1->right->val;
            }
            if (root2->left != NULL)
            {
                root2_left_val = root2->left->val;
            }
            if (root2->right != NULL)
            {
                root2_right_val = root2->right->val;
            }
            if (root1_left_val == root2_right_val && root1_right_val == root2_left_val)
            {
                swapSubTree(root1);
            }
            return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ? true : false;
        }
            
        return false;
    }
};
//1st tree
//1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 6 -1 -1 -1
//2nd tree 
//1 3 -1 6 -1 -1 2 4 -1 -1 5 8 -1 -1 7 -1 -1
int main() {
    Solution solution;

    cout<<"1st tree"<<endl;
    TreeNode * root1 = solution.createTree();
    cout<<"2nd tree"<<endl;
    TreeNode * root2 = solution.createTree();
    cout<<"input end"<<endl;
    solution.printTree(root1);
    solution.printTree(root2);
    cout<<"------"<<endl;

    cout<<solution.flipEquiv(root1, root2)<<endl;

    return 0;

}