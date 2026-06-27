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
    int maxSum(TreeNode* root,int& pathSum){
        if(root==NULL) return 0;

        int leftGain=max(0,maxSum(root->left,pathSum));
        int rightGain=max(0,maxSum(root->right,pathSum));

        pathSum=max(pathSum, leftGain+root->val+rightGain);

        return root->val +max(leftGain,rightGain);
    }
    int maxPathSum(TreeNode* root) {
        int pathSum=INT_MIN;
        maxSum(root,pathSum);
        return pathSum;
    }
};