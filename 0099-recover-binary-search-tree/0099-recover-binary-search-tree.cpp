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
    TreeNode* firstViolation=nullptr;
    TreeNode* secondViolation=nullptr;
    TreeNode* adjacentToFirst=nullptr;
    TreeNode* prev=nullptr;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev && root->val<prev->val &&!firstViolation){
            firstViolation=prev;
            adjacentToFirst=root;
        }
        if(prev && root->val<prev->val && firstViolation){
            secondViolation=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(firstViolation && secondViolation){
            swap(firstViolation->val,secondViolation->val);
        }
        else swap(firstViolation->val,adjacentToFirst->val);
    }
};