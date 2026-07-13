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
    void childParentMapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &childParent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
                childParent[current->left]=current;
            }
            if(current->right){
                q.push(current->right);
                childParent[current->right]=current;
            }
        }
    }

    TreeNode* startNode(TreeNode* root,int start){
        if(!root) return nullptr;
        if(root->val==start) return root;
        TreeNode* left=startNode(root->left,start);
        if(left) return left;
        return startNode(root->right,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> childParent;
        childParentMapping(root,childParent);
        unordered_map<TreeNode*,int> visited;
        TreeNode* Start=startNode(root,start);
        queue<TreeNode*> q;
        q.push(Start);
        visited[Start]=1;
        int time =0;
        while(!q.empty()){
            int size=q.size();
            bool infected=false;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited.count(current->left)){
                    q.push(current->left);
                    visited[current->left]=1;
                    infected=true;
                }
                if(current->right && !visited.count(current->right)){
                    q.push(current->right);
                    visited[current->right]=1;
                    infected=true;
                }
                if(childParent.count(current) && !visited.count(childParent[current])){
                    q.push(childParent[current]);
                    visited[childParent[current]];
                    infected=true;
                }
            }
            if(infected) time++;
        }
        return time;
    }
};