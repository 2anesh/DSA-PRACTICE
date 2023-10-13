class Solution {
    public int minCostClimbingStairs(int[] cost) {
       int dp[]=new int[cost.length];
        Arrays.fill(dp,-1);
      int   amount1=climbStairs(cost,0,dp);
       int amt2=climbStairs(cost,1,dp);
        return Math.min(amount1,amt2);
        
    }
    public int climbStairs(int cost[],int i,int dp[])
    {
        if(i>=cost.length)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int cost1=cost[i]+climbStairs(cost,i+1,dp);
        int cost2=cost[i]+climbStairs(cost,i+2,dp);
        return dp[i]=Math.min(cost1,cost2);
    }
}
