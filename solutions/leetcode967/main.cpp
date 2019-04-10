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
    void getNumber(TreeNode * root, int level, int value, vector<int>& res) {
        if(root == NULL||level <= 0)
            return ;
        if (level == 1) {
            value += root->val;
            res.push_back(value);
            return ;
        }
        value += root->val * pow(10, level-1);
        getNumber(root->left, level-1, value, res);
        getNumber(root->right, level-1, value, res);
    
    }
    TreeNode * createTree(int root_val, int level, int k)
    {
        if(root_val<0 || root_val > 9 || level == 0)
            return NULL;
        TreeNode * root = new TreeNode(root_val);
        if(k == 0)
            root->left = NULL;
        else
            root->left = createTree(root_val - k, level-1, k);
        root->right = createTree(root_val + k, level-1, k);

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

    vector<int> numsSameConsecDiff(int N, int K)
    {
        if(N == 1)
            return vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> res;

        for (int i = 1; i <= 9; ++i) {
            TreeNode * root = createTree(i, N, K);
            getNumber(root, N, 0, res);
        }
        return res;
    }


};

int main() {
    Solution solution;
    
    vector<int> res = solution.numsSameConsecDiff(2, 0);

    for(auto iter : res)
        cout<<iter<<endl;

    return 0;


}