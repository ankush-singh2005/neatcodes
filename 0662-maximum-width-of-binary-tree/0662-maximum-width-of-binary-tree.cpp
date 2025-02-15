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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> dq;
        dq.push({root,0});
        ll ans=0;
        if(root==NULL) return ans;
        while(!dq.empty()){
            int n=dq.size();
            ll L=dq.front().second;
            ll R=dq.back().second;
            ans=max(ans,R-L+1);
            while(n--){
                auto it=dq.front();
                TreeNode* node=it.first;
                ll idx=it.second;
                dq.pop();
                if(node->left!=NULL) dq.push({node->left,(2*idx)+1});
                if(node->right!=NULL) dq.push({node->right,(2*idx)+2}); 
            }
        }
        return ans;
    }
};