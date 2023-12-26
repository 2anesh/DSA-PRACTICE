class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        // Use a 2D array for dynamic programming
        int[][] dp = new int[n + 1][target + 1];
        int mod = 1000000007;

        // Base case: one way to achieve a target of 0 with 0 dice
        dp[0][0] = 1;

        // Fill in the dp array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                // Calculate the current dp value based on the previous row
                for (int x = 1; x <= k && x <= j; x++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
                }
            }
        }

        return dp[n][target];
    }
}
