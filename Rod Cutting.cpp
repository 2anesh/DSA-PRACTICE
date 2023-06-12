class Solution{
    public:
    int solve(int n ,int need,int sum,int price[],vector<int>&dp){
        if(need==0) return sum;
        if(dp[need-1]!= -1) return sum+dp[need-1];
        int maxi=0;
        for(int j=1;j<=need;j++){
            maxi= max(maxi,solve(n,need-j,sum+price[j-1],price,dp));
        }
        dp[need-1]=maxi-sum;
        return maxi;
    }
    int cutRod(int price[], int n) {
        vector<int>dp(n,-1);
        int x =solve(n,n,0,price,dp);
        return x;
    }
};
