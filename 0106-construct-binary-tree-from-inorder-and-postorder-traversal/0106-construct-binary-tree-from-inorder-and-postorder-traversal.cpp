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
    unordered_map<int,int> mpp;
    

    TreeNode* buildTree(vector<int>& postorder,int& n,int left,int right){
        if(left>right) return nullptr;

        int rootVal=postorder[n];
        n--;
        TreeNode* root=new TreeNode(rootVal);
        int mid=mpp[rootVal];

        root->right=buildTree(postorder,n,mid+1,right);
        root->left=buildTree(postorder,n,left,mid-1);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        int n=postorder.size()-1;
        return buildTree(postorder,n,0,inorder.size()-1);
    }
};