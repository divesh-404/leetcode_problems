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
// recursive method
    // void preOrder(TreeNode* root, vector<int>& ans){
    //     if(root==NULL) return;
    //     ans.push_back(root->val);
    //     preOrder(root->left,ans);
    //     preOrder(root->right,ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // preOrder(root,ans);
        // return ans;

        //iterative method

        // vector<int> ans;
        // if(root==NULL) return ans;
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     root=st.top();
        //     st.pop();
        //     ans.push_back(root->val);
        //     if(root->right!=NULL){
        //         st.push(root->right);
        //     }
        //     if(root->left!=NULL){
        //         st.push(root->left);
        //     }
        // }
        // return ans;

         //morris preorder travesral
        vector<int> preorder;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    curr=curr->right;
                }
            }
        }

        return preorder;
    }
};