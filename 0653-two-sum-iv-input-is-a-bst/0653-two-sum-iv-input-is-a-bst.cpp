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
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    void small(TreeNode* root){
        while(root){
            st1.push(root);
            root=root->left;
        }
    }
     void greater(TreeNode* root){
        while(root){
            st2.push(root);
            root=root->right;
        }
    }
    int nextSmaller(){
        TreeNode* el=st1.top();
        st1.pop();
        if(el->right){
            small(el->right);
        }
        return el->val;
    }

    int nextGreater(){
        TreeNode* el=st2.top();
        st2.pop();
        if(el->left){
            greater(el->left);
        }
        return el->val;
    }

    bool findTarget(TreeNode* root, int k) {
        small(root);
        greater(root);
        int left=nextSmaller();
        int right=nextGreater();
        while(left<right){
            if(left+right==k) return true;
            else if(left+right>k) right=nextGreater();
            else left=nextSmaller();
        }
        return false;
    }
};