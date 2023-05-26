class Solution
{
    public static int mod = 1000000007;
    public static int fun(int ind, int n, int x, int [][] dp){
        if(ind > n){
            if(n == 0) return 1;
            return 0;
        }
        if(dp[ind][n] != -1) return dp[ind][n];
        int pick=0;
        if(n>0){
            pick = fun(ind+1, n-(int)Math.pow(ind,x), x, dp);
        }
        int notpick = fun(ind+1, n, x, dp);
        return dp[ind][n] = (pick+notpick)%mod;
    }
    static int numOfWays(int n, int x)
    {
        int [][] dp = new int[n+1][n+1];
        for(int i=0; i<dp.length; i++){
            for(int j=0; j<dp[0].length; j++) dp[i][j] = -1;
        }
        return fun(1, n, x, dp);
    }
}

