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
    void solve(TreeNode* root, int &min, long &secondMin){
        if(root==NULL) return;
        if(root->val>min && root->val<secondMin){
            // min=secondMin;
            secondMin=root->val;
        }
        solve(root->left, min, secondMin);
        solve(root->right, min, secondMin);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        int min=root->val;
        long secondMin=LONG_MAX;
        solve(root, min, secondMin);
        return secondMin==LONG_MAX?-1:secondMin;
    }
};