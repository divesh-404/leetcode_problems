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
    int c=0;
    void totalNodes(TreeNode* root){
        if(root==nullptr) return;
        c++;
        totalNodes(root->left);
        totalNodes(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        totalNodes(root);
        return c;
        // queue<TreeNode*> q;
        // q.push(root);
        // int ans=0;
        // while(!q.empty()){
        //    int size=q.size();
        //    ans+=size;
        //    for(int i=0;i<size;i++){
        //         TreeNode* current=q.front();
        //         q.pop();
        //         if(current->left) q.push(current->left);
        //         if(current->right) q.push(current->right);
        //    }
        // }
        // return ans;
    }
};