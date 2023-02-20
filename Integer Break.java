class Solution {

public int integerBreak(int n) {
    int[] dp = new int[n+1];
    Arrays.fill(dp, -1);
    return memo(n, dp);
}

public int memo(int n, int[] dp){
    if(n == 1) return n;
    if(dp[n] != -1) return dp[n];
    int i = 1;
    int ans = 1 * (n-1);
    while(i <= n){
        ans = Math.max(ans, i * Math.max(n-i, memo(n-i, dp)));
        i++;
    }
    
    return dp[n] = ans;
}
}
