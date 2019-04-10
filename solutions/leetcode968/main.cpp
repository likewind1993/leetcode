#include <algorithm>
#include <iostream>
#include <vector>
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
    int minCameraCover(TreeNode* root)
    {
        vector<int> ans = solve(root);

        return min(ans[1], ans[2]);

    }
    vector<int> solve(TreeNode* node) {
        if(node == NULL)
            return vector<int>{0, 0, 99999};
        
        vector<int> L = solve(node->left);
        vector<int> R = solve(node->right);

        int mL12 = min(L[1], L[2]);
        int mR12 = min(R[1], R[2]);
        
        int d0 = L[1] + R[1];
        int d1 = min(L[2] + mR12, R[2] + mL12);
        int d2 = 1 + min(L[0], mL12) + min(R[0], mR12);

        return vector<int>{d0, d1, d2};
    }
};

int main() {
    Solution solution;
    TreeNode * root = solution.createTree();

    cout<<solution.minCameraCover(root)<<endl;

    return 0;


}