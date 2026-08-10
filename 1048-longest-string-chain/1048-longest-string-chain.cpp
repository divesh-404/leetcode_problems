class Solution {
public:
    bool check(string& s1,string& s2){
        if(s1.size()!=s2.size()+1) return false;

        int first=0,second=0;

        while(first<s1.size() && second<s2.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }
            else first++;
        }
        return second==s2.size();
    }


    int longestStrChain(vector<string>& words) {
        int n=words.size();

        sort(words.begin(),words.end(),[](string& a,string& b){
            return a.size()<b.size();
        });

        int maxi=1;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int pi=0;pi<i;pi++){
                if(check(words[i],words[pi]) && 1+dp[pi]>dp[i]){
                    dp[i]=1+dp[pi];
                }
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};