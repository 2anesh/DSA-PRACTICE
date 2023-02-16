class Solution {
    public int longestPalindromeSubseq(String s) {
        
        int len = s.length();
        
        if (s == null || len == 0) {
            return 0;
        }

        String revString = new StringBuilder(s).reverse().toString();

        int dp[][] = new int[len + 1][len + 1];

        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= len; j++) {

                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (s.charAt(i - 1) == revString.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
                
            }
        }
        return dp[len][len];
    }
}
