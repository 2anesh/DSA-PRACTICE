class Solution {
     public static int goodStones(int n, int[] arr) {
        // code here
        // 0: not-visited, 1: process
        // 2: good,        3: bad
        int[] dp = new int[n];
        int ans = 0;
        
        for(int i=0; i<n; i++){
            // cheching only non-proccessed stones
            if(dp[i] == 0){
                helper(i, dp, arr);
            }
        }
        
        for(int c: dp){
            // considering only good stone
            if(c == 2) ans++;
        }
        
        return ans;
    }
    
    static int helper(int index, int[] dp, int[] arr){
        // if out-of-boud then no loop possible using that index or stone
        if(index >= arr.length || index < 0) return 2;
        
        // returning good or bad count
        if(dp[index] >= 2) return dp[index];
        
        // we are visiting same index which is still under process - bad stone
        if(dp[index] == 1) return 3;
        
        
        // 1 means we are processing this index
        dp[index] = 1;
        
        // calculating next index
        int next = index + arr[index];
        
        // adding status{0,1,2,3}
        dp[index] = helper(next, dp, arr);
        
        return dp[index];
    }
}
        
