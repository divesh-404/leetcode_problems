class Solution {
public:
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    string b;

    void dfs(string word,vector<string>& seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
        }
        int steps=mpp[word];
        for(int i=0;i<word.size();i++){
            char org=word[i];
            for(char ch='a';ch<='z';ch++){
                if(ch==org) continue;
                word[i]=ch;
                if(mpp.count(word) && steps==mpp[word]+1){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=org;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // unordered_set<string> st(wordList.begin(),wordList.end());
        // vector<vector<string>> ans;
        // if(!st.count(endWord)) return ans;
        // queue<vector<string>> q;
        // q.push({beginWord});
        // vector<string> usedOnLevel;
        // usedOnLevel.push_back(beginWord);
        // int level=0;
        // while(!q.empty()){
        //     vector<string> vec=q.front();
        //     q.pop();
        //     // removing the words from the set after one whole level traversal is done
        //     if(vec.size()>level){
        //         level++;
        //         for(auto it:usedOnLevel){
        //             st.erase(it);
        //         }
        //         usedOnLevel.clear();
        //     }

        //     string word=vec.back();
        //     //store the ans
        //     if(word==endWord){
        //         //the first seq where we reached the end word
        //         if(ans.size()==0){
        //             ans.push_back(vec);
        //         }
        //         //other sequences if the size is same as the first one 
        //         else if(ans[0].size()==vec.size()){
        //             ans.push_back(vec);
        //         }
        //     }

        //     for(int i=0;i<word.size();i++){
        //         char original=word[i];
        //         for(char ch='a';ch<='z';ch++){
        //             if(ch==original) continue;
        //             word[i]=ch;
        //             if(st.count(word)){
        //                 vec.push_back(word);
        //                 q.push(vec);
        //                 usedOnLevel.push_back(word);
        //                 vec.pop_back();
        //             }
        //         }
        //         word[i]=original;
        //     }
        // }

        // return ans;

        // dfs + backtracking apporach
        b=beginWord;
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(!st.count(endWord)) return ans;

        queue<string> q;
        q.push({b});
        st.erase(b);
        mpp[b]=1;
        int sz=b.size();
        while(!q.empty()){
            string word=q.front();
            int steps=mpp[word];
            q.pop();
            if(word==endWord) break;

            for(int i=0;i<sz;i++){
                char org=word[i];
                for(char ch='a';ch<='z';ch++){
                    if(ch==org) continue;
                    word[i]=ch;
                    if(st.count(word)){
                        q.push(word);
                        mpp[word]=steps+1;
                        st.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        if(mpp.count(endWord)){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }

        return ans;
    }
};