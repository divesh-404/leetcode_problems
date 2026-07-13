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
    void secondMinimum(TreeNode* root, int minVal,long long &secondMin){
        if(!root) return;
        secondMinimum(root->left,minVal,secondMin);
        if(root->val>minVal) secondMin=min(secondMin,(long long)root->val);
        secondMinimum(root->right,minVal,secondMin);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int minVal=root->val;
        long long secondMin=LLONG_MAX;
        secondMinimum(root,minVal,secondMin);
        if(secondMin==LLONG_MAX) return -1;
        else return (int)secondMin;

    }
};