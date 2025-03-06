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
    void solve(TreeNode* root){
        if(!root) return;
        swap(root->left, root->right);
        solve(root->left);
        solve(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        solve(root);
        return root;
    }
    // void solve(TreeNode* left, TreeNode* right){
    //     if(left==NULL || right==NULL) return;
    //     swap(left->val, right->val);
    //     solve(left->right, right->left);
    //     solve(left->left, right->right);
    // }

    // TreeNode* invertTree(TreeNode* root) {
    //     if(root==NULL) return root;
    //     solve(root->left, root->right);
    //     return root;
    // }
};