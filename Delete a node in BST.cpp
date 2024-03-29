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
    TreeNode* deleteNode(TreeNode* root, int key) {

        //checking if root is not eqaul to null
        if(root){

            //condition to get to the node that is to be deleted
            if(key<root->val) 
                root->left=deleteNode(root->left,key);
            else if(key>root->val) 
                root->right=deleteNode(root->right,key);

            //when reached the node that is to be deleted    
            else{

                //case 1: node has no children
                //simply delete the node
                if(root->right==NULL && root->left==NULL) return NULL;

                //case 2: node has 1 children
                //if there's a value in left node return left node else return rigth node
                if(!root->left || !root->right) 
                    return root->left?root->left:root->right;

                
                //case 3: when root has 2 child nodes
                // using the max value from the right subtree 
                TreeNode* temp=root->left;
                //reaching the end of the right subtree
                while(temp->right!=NULL) temp=temp->right;

                //copying the value of the min to root
                root->val=temp->val;

                //finally deleting the copied value
                root->left=deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
};
