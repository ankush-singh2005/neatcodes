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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx, unordered_map<int, int> &mp){
        if(start>end) return NULL;
        int rootVal=postorder[idx];
        idx--;
        // int i=start;
        // for(; i<=end;i++){
        //     if(inorder[i]==rootVal) break;
        // }

        int i=mp[rootVal];
        TreeNode* root=new TreeNode(rootVal);
        root->right=solve(inorder, postorder, i+1, end, idx, mp);
        root->left=solve(inorder, postorder, start, i-1, idx, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(inorder, postorder, 0, postorder.size()-1, idx, mp);
    }
};