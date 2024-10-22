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
void calculateLevelSum(TreeNode* root, int level, vector<long long>& sum){
    if(root==nullptr) return;
    sum[level]+=root->val;
    calculateLevelSum(root->left, level+1, sum);
    calculateLevelSum(root->right, level+1, sum);
}

    long long getHeight(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr) return 0;

        int left=0;
        if(root->left!=nullptr){
            left=getHeight(root->left);
        }
        int right=0;
        if(root->right!=nullptr){
            right=getHeight(root->right);
        }

        return max(left,right)+1;
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long h=getHeight(root)+1;
        vector<long long> sum(h,0);
        calculateLevelSum(root,0,sum);
        sort(sum.begin(), sum.end(), greater<long long>());
        if (k > sum.size()) return -1; 
        return sum[k-1];
    }
};
