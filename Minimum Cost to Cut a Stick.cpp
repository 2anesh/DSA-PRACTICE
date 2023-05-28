class Solution {
public:
    int percuts(vector<int>& cuts,int i,int j,int start,int end,vector<vector<int>>& dp){
        if(i > j){
            return 0;
        }
        else if(dp[i][j] != -1){
            return dp[i][j];
        }
        else{
            int ans = INT_MAX;
            for(int k = i; k <= j; k++){
                ans = min(ans,percuts(cuts,i,k-1,start,cuts[k],dp) + percuts(cuts,k+1,j,cuts[k],end,dp) + (end - start));
            }
            return dp[i][j] = ans;
        }
    }
    int minCost(int n, vector<int>& cuts) {
        ios_base::sync_with_stdio(0);
        int m = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return percuts(cuts,0,m-1,0,n,dp);
    }
};
