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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //both trees are empty
       if(p==nullptr && q==nullptr) return true;
        //one is empty and other dont
       if(p==nullptr || q==nullptr) return false;
       //check the values
       if(p->val!=q->val) return false;
       //check the leftTree and rightTree
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};