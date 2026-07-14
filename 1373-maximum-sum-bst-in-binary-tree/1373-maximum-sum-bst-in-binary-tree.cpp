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
class NodeValue{
public:
    int min,max,maxSum;
    NodeValue(int min,int max,int maxSum){
        this->min=min;
        this->max=max;
        this->maxSum=maxSum;
    }
};

class Solution {
    int ans=0;
    NodeValue solve(TreeNode* root){
        if(!root) return NodeValue(INT_MAX,INT_MIN,0);

        auto left=solve(root->left);
        auto right=solve(root->right);

        if(root->val>left.max && root->val<right.min){
            int curSum=left.maxSum+right.maxSum+root->val;
            ans=max(ans,curSum);
            return NodeValue(min(root->val,left.min),max(root->val,right.max),curSum);
        }

        return NodeValue(INT_MIN,INT_MAX,0);
    }
public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        if(ans<0) return 0;
        return ans;
    }
};