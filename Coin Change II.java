class Solution {
  public int solve(int i, int target, int[] coins){
    if(i==0){
      if(target%coins[i]==0)return 1;
      return 0;
    }
    
    int notTake=solve(i-1,target,coins);
    int take=0;
    if(coins[i]<=target){
      take=solve(i,target-coins[i],coins);
    }
    
    return notTake+take;
  }
    public int solve_Dp(int i, int target, int[] coins,int[][] dp){
    if(i==0){
      if(target%coins[i]==0)return 1;
      return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    
    int notTake=solve_Dp(i-1,target,coins,dp);
    int take=0;
    if(coins[i]<=target){
      take=solve_Dp(i,target-coins[i],coins,dp);
    }
    
    return dp[i][target]=notTake+take;
  }
    public int solve_Tab(int T, int[] arr){
      int n=arr.length;
      int[][] dp=new int[n][T+1];

      for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            dp[0][i]=1;
    }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=T;target++){
            int notTaken = dp[ind-1][target];
            
            int taken = 0;
            if(arr[ind]<=target)
                taken = dp[ind][target-arr[ind]];
                
            dp[ind][target] = notTaken + taken;
        }
    }
    
    return dp[n-1][T];
    }
    public int solve_Space(int T, int[] arr){
     int[] prev=new int[T+1];
    int n=arr.length;

    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            prev[i]=1;
    }
    
    for(int ind=1; ind<n;ind++){
        int cur[]=new int[T+1];
        for(int target=0;target<=T;target++){
            int notTaken = prev[target];
            
            int taken = 0;
            if(arr[ind]<=target)
                taken = cur[target-arr[ind]];
                
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    
    return prev[T];
    }
    public int change(int target, int[] coins) {
        int n=coins.length; 
        return solve_Space(target,coins);
    }
}
