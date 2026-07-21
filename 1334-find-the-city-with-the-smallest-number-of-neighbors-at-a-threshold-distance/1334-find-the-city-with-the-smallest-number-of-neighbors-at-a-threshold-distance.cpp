class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        for(auto it:edges){
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][via]!=INT_MAX && dis[via][j]!=INT_MAX){
                        dis[i][j]=min(dis[i][j],(dis[i][via]+dis[via][j]));
                    }
                }
            }
        }

        int minCount=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && dis[i][j]<=distanceThreshold) count++;
            }
            if(count<=minCount){
                minCount=count;
                ans=i;
            }
        }
        return ans;
    }
};