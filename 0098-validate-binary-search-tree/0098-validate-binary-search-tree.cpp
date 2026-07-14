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
    int ans=1;
    long long element=LLONG_MIN;
    void inorder(TreeNode* root,int &ans,long long &element){
        if(!root) return;
        inorder(root->left,ans,element);
        if(root->val<=element){
            ans=0;
            return;
        }
        element=root->val;
        inorder(root->right,ans,element);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root,ans,element);
        return ans;

    }
};