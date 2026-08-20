bool solve(int dist,int m,vector<int>& position){
    int prev=position[0];
    m--;
    for(int i=1;i<position.size();i++){
        if(position[i]-prev>=dist){
            prev=position[i];
            m--;
        }
        if(m==0) return true;
    }

    return false;
}
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int l=1;
        int h=position[n-1]-position[0];
        int ans=0;

        while(l<=h){
            int dist=l+(h-l)/2;
            
            if(solve(dist,m,position)){
                ans=dist;
                l=dist+1;
            }
            else{
                h=dist-1;
            }
        }
        return ans;
    }
};