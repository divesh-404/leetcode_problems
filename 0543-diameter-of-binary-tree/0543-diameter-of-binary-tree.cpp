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
    int maxDia(TreeNode* root,int& dia){
        if(root==NULL) return 0;
        int lh=maxDia(root->left,dia);
        int rh=maxDia(root->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        maxDia(root,dia);
        return dia;
    }
};