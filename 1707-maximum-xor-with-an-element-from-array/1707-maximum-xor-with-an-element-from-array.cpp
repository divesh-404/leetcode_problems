struct Node{
    Node* links[2];
    Node(){
        links[0]=links[1]=nullptr;
    }
    bool containsKey(int bit){
        return links[bit]!=nullptr;
    }

    void put(int bit,Node* node){
        links[bit]=node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
    Node* root;

    public:

    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1; //gives 1 0r 0
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int getMax(int num){
        int maxi=0;
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxi=maxi|(1<<i);
                node=node->get(1-bit);
            }
            else node=node->get(bit);
        }

        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;

        sort(nums.begin(),nums.end());
        
        vector<vector<int>> querie;

        for(int i=0;i<queries.size();i++){
            querie.push_back({queries[i][1],queries[i][0],i});
        }
        sort(querie.begin(),querie.end());

        vector<int> ans(queries.size());

        int i=0;
        for(auto &it:querie){
            while(i<nums.size() && nums[i]<=it[0]){
                trie.insert(nums[i]);
                i++;
            }
            if(i==0) ans[it[2]]=-1;
            else ans[it[2]]=trie.getMax(it[1]);
        }

        return ans;
    }
};