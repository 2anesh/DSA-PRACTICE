class Solution {
    
    public int fun(int Target, int i, int [][] dp){
        if(i == 1) {
            if(Target % (i*i) == 0) return Target /(i*i);
            return (int)1e9;
        }
        if(Target == 0) return 0;
        int NotInclude = 0;
        if(dp[i][Target] > 0) return dp[i][Target];
        NotInclude = 0 + fun(Target , i-1, dp);
        int Include = (int)1e9;
        if(Target >= i*i){
            Include = 1 + fun(Target - i*i , i, dp);
        }
        
        int ans =  Math.min(Include, NotInclude);
        // System.out.println("ans is "+ ans);
        return dp[i][Target] = ans;
    }
    public int numSquares(int n) {
        int i= (int)Math.sqrt(n);
        int dp[][] = new int[i+1][n+1];
        return fun(n, i, dp);
    }
}
