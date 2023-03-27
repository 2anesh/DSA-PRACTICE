class Solution {
  public int countWaystoDivide(int N, int K) {
        // Code here
        return f(N,K,1,new Integer[N+1][K+1][N+1]);
    }
    public static int f(int sum,int k,int previousElement,Integer[][][] dp) {
        if(k==0 && sum==0) return 1;
        if(k==0 || sum<=0) return 0;
        if(dp[sum][k][previousElement]!=null) return dp[sum][k][previousElement];
        
        int ans=0;
        for(int i=previousElement;i<=sum;i++) {
            ans+=f(sum-i,k-1,i,dp);
        }
        return dp[sum][k][previousElement]=ans;
    }
}
