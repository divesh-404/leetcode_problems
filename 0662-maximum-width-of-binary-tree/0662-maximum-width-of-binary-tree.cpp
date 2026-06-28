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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long miniIndex=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                long long currId=q.front().second-miniIndex;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=currId;
                if(i==size-1) last=currId;
                if(node->left) q.push({node->left,1ll*2*currId+1});
                if(node->right) q.push({node->right,1ll*2*currId+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};