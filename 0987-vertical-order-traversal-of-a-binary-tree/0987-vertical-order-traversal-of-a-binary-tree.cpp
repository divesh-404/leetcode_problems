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
    // void storeTuples(TreeNode* root,vector<tuple<int,int,int>>& tuples,int row,int col){
    //     if(root==NULL) return;
    //     tuples.push_back({col,row,root->val});
    //     storeTuples(root->left,tuples,row+1,col-1);
    //     storeTuples(root->right,tuples,row+1,col+1);
    // }

    void f(TreeNode* root,map<int,vector<pair<int,int>>>& mp,int row,int col){
        if(root==nullptr) return;
        mp[col].push_back({row,root->val});
        f(root->left,mp,row+1,col-1);
        f(root->right,mp,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //tuples solution

        // vector<tuple<int,int,int>> tuples;
        // storeTuples(root,tuples,0,0);
        // if(tuples.empty()) return {};

        // sort(tuples.begin(),tuples.end());

        // vector<vector<int>> ans;
        // int n=tuples.size();
        // int i=0;
        // int column=get<0>(tuples[0]);
        // while(i<n){
        //     vector<int> row;
        //     while(i<n && get<0>(tuples[i])==column){
        //         row.push_back(get<2>(tuples[i]));
        //         i++;
        //     }
        //     ans.push_back(row);
        //     if(i<n) column=get<0>(tuples[i]);
        // }

        // return ans;

        // map solution
        map<int,vector<pair<int,int>>> mp;
        f(root,mp,0,0);
        vector<vector<int>> ans;

        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            int size=it.second.size();
            vector<int> col;
            for(int i=0;i<size;i++){
                col.push_back(it.second[i].second);
            }
            ans.push_back(col);
        }
        return ans;
    }
};