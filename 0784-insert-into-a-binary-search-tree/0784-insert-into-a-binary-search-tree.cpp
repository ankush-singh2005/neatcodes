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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* n=new TreeNode(val);
            return n;
        }
        TreeNode* curr=root;
        while(true){
            if(val>=curr->val){
                if(curr->right) curr=curr->right;
                else{
                    TreeNode* temp=new TreeNode(val);
                    curr->right=temp;
                    break;
                }
            }
            else{
                if(curr->left) curr=curr->left;
                else{
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};