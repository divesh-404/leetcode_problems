/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void TreeToString(TreeNode* root,string& ans){
        if(root==nullptr){
            ans+="# ";
            return;
        }
        ans+=to_string(root->val)+" ";
        TreeToString(root->left,ans);
        TreeToString(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        TreeToString(root,ans);
        return ans;
    }

    TreeNode* stringToTree(stringstream& ss){
        string token;
        ss>>token;

        if(token=="#") return nullptr;

        TreeNode* root= new TreeNode(stoi(token));

        root->left=stringToTree(ss);
        root->right=stringToTree(ss);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return stringToTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));