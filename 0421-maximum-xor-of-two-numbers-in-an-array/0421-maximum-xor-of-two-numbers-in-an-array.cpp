struct Node{
    Node* links[2];
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
            int bit=(num>>i)&1; //gives 1 or 0 on that ith place
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int maximize(int num){
        int maxi=0;
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxi=maxi | (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }

        return maxi;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for(auto &it: nums){
            trie.insert(it);
        }
        int maxAns=0;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j<i;j++){
                maxAns=max(maxAns,trie.maximize(nums[j]));
            }
        }

        return maxAns;
    }
};