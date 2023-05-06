class Solution {
     public static boolean makeChanges(int n, int k, int t, int[] coins) {
        int dp[][] = new int[k+1][t+1];
        for(int []r: dp) Arrays.fill(r, -1);
      return solve(0, k, t, coins, dp);
    }
    public static boolean solve(int i, int k, int t, int[] coins, int dp[][]) {
      if(i == coins.length){
          if(k == 0 && t == 0) return true;
          else return false;
      }
      if(dp[k][t] != -1) return dp[k][t] == 1;
      boolean take = false, notTake = false;
      
      if(t>=coins[i] && k>0){
          take = solve(i, k-1, t-coins[i], coins, dp);
      }
          notTake = solve(i+1, k, t, coins, dp);
          if(take || notTake) dp[k][t] = 1;
          else dp[k][t] = 0;
        return take || notTake;
    }
}
