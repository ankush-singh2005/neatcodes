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
    void solve(TreeNode* root, stack<int> &st, int level){
        if(root==nullptr) return;
        if(st.size()==level) st.push(root->val);
        solve(root->left,st,level+1);
        solve(root->right,st,level+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        stack<int> st;
        solve(root,st,0);
        return st.top();
    }
};