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
    void solve(TreeNode* root, vector<int> &num){
        if(root==NULL) return;
        solve(root->left,num);
        num.push_back(root->val);
        solve(root->right,num);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> num;
        solve(root, num);
        int i=0,j=num.size()-1;
        while(i<j){
            if(num[i]+num[j]==k) return true;
            if(num[i]+num[j]>k) j--;
            else i++;
        }
        return false;
    }
};