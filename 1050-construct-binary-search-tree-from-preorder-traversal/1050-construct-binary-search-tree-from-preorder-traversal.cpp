/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int &ind, vector<int> &preorder, int left, int right){
        if(ind>=preorder.size()) return nullptr;
        int value=preorder[ind];

        if(value<left || value>right) return nullptr;

        TreeNode* root=new TreeNode(value);
        ind++;
        root->left=solve(ind, preorder, left, value);
        root->right=solve(ind, preorder, value, right);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return solve(ind, preorder, INT_MIN, INT_MAX);
    }
};