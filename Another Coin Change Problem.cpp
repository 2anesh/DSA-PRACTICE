class Solution {
    private:
    bool caldp(int idx, int k, int tr, vector<int>&coin, vector<vector<int>>&dp)
    {
        if(tr==0){
           return (k==0);
           /* using an infinite supply of each coin but the total number of coins used must be exactly equal to k.*/
        }
        if(idx==0){
            return (tr/coin[idx]==k && tr%coin[idx]==0);
        }
        
        if(dp[tr][k]!=-1){
            return dp[tr][k];
        }
        bool nttk=caldp(idx-1,k,tr,coin,dp);
        bool ttk=false;
        if(tr>=coin[idx]){
            ttk=caldp(idx,k-1,tr-coin[idx],coin,dp);
        }
        return dp[tr][k]=(ttk||nttk);
    }
  public:
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
       vector<vector<int>>dp(target+1,(vector<int>(k+1,-1)));
       return caldp(n-1,k,target,coins,dp);
    }
};

 
