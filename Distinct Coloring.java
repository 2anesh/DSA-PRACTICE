class Solution{
    public static long distinctColoring(int n, int[]r, int[]g, int[]b){
        //code here
        int arr[][] = new int[n][3];
        for(int i = 0;i<n;i++){
            arr[i][0] = r[i];
            arr[i][1] = g[i];
            arr[i][2] = b[i];
        }
        long dp[][] = new long[n][3];
        for(long a[] : dp) Arrays.fill(a, -1);
        long ans = Math.min(Math.min(util(0, 0,  arr, dp), util(0, 1,  arr, dp)), util(0, 2,  arr, dp));
        return ans;
    }
    public static long util(int i, int curr, int[][] arr, long dp[][]){
        if(i == arr.length) return 0;
        if(dp[i][curr] != -1) return dp[i][curr];
        long p = 0, q = 0;
        if(curr == 0){
            p= util(i+1, 1, arr, dp)+arr[i][1];
            q = util(i+1, 2, arr, dp)+arr[i][2];
        }
        if(curr == 1){
            p = util(i+1, 0, arr, dp)+arr[i][0];
            q = util(i+1, 2, arr, dp)+arr[i][2];
        }
        if(curr == 2){
            p = util(i+1, 0, arr, dp)+arr[i][0];
            q = util(i+1, 1, arr, dp)+arr[i][1];
        }
        return  dp[i][curr] = Math.min(p, q);
    }
}
