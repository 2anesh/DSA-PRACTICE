class Solution {
  public:
     long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(N+1, vector<long long int>(sum+1, 0));
        
        for(int i=0; i<=N; i++){
            dp[i][0]=1;
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                long long int take=0;
                if(coins[i-1]<=j){
                    take=dp[i][j-coins[i-1]];
                }
                long long int ntake=dp[i-1][j];
                dp[i][j]=take+ntake;
            }
        }
        
        return dp[N][sum];
    }
};
