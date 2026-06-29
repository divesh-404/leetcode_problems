/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void childParentMapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& childParent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current->left){
                childParent[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                childParent[current->right]=current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> childParent;
        childParentMapping(root,childParent);

        unordered_map<TreeNode*,int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=1;
        int distance=0;
        while(!q.empty()){
            int size=q.size();
            if(distance++==k) break;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited.count(current->left)){
                    q.push(current->left);
                    visited[current->left]=1;
                }
                if(current->right && !visited.count(current->right)){
                    q.push(current->right);
                    visited[current->right]=1;
                }
                if(childParent.count(current) && !visited.count(childParent[current])){
                    q.push(childParent[current]);
                    visited[childParent[current]]=1;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};