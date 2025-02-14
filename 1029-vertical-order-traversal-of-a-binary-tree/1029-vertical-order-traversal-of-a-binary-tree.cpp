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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> todo;
        todo.push({root, {0,0}});
        while(!todo.empty()){

            //taking out the first element of the queue
            auto p=todo.front();
            todo.pop();

            //storing the node in a variable
            TreeNode* node=p.first;

            //in x we have stored the axis value ie the vertical index that we habve taken 
            // and in y we have stored the value of the level as we are going down
            int x=p.second.first, y=p.second.second;

            //here we are storing the node value along with its axis and the level value in the map
            nodes[x][y].insert(node->val);

            //inserting the nodes in the map if it exists
            if(node->left!=nullptr){
                //when going left the axis value will decrease by one and the level value +1
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right!=nullptr){
                //when going right the axis value will inc by one and the level value dec by 1
                todo.push({node->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};