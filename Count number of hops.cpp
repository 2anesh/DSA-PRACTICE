class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod=1000000007;
    //Function to count the number of ways in which frog can reach the top.
    long long solve(int n,vector<int>&dp){
        //basecase
        if(n==0)return 1;
        
        if(dp[n]!=-1)return dp[n];
        long long a=0;
        if(n>=1){
             a= solve(n-1,dp);
        }
        long long b=0;
        if(n>=2){
            b= solve(n-2,dp);
        }
        long long c=0;
        if(n>=3){
            c=solve(n-3,dp);
        }
        return dp[n]=(a%mod+b%mod+c%mod)%mod;
    }
    long long countWays(int n)
    {
        // long long cnt=0;
        vector<int>dp(n+1,-1);
        return solve(n,dp);
        
    }
};
