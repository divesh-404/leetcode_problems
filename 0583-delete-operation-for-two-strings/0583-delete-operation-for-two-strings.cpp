class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        // if(n==1 && m==1 && word1[0]==word2[0]) return 0;

        vector<int> prev(m+1,0),curr(m+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }

        return (m-prev[m])+(n-prev[m]);
    }
};