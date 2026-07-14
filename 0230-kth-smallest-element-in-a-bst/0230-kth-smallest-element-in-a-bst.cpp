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
    int count=0;
    // void inorder(TreeNode* root,int k,int &ans){
    //     if(!root || count>=k) return;
    //     inorder(root->left,k,ans);
    //     count++;
    //     if(count==k){
    //         ans=root->val;
    //         return;
    //     }
    //     inorder(root->right,k,ans);
    // }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        // inorder(root,k,ans);
        // return ans;

        //morris approach for O(1) space 
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                count++;
                if(count==k){
                    ans=curr->val;
                }
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    count++;
                    if(count==k){
                        ans=curr->val;
                    }
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};