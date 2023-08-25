class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        int rows = s1.length();
        int cols = s2.length();
        boolean[][] dp = new boolean[rows + 1][cols + 1];
        dp[rows][cols] = true;
        for (int i = rows; i >= 0; i--) {
            for (int j = cols; j >= 0; j--) {
                if (i < rows && s3.charAt(i + j) == s1.charAt(i) && dp[i + 1][j]) {
                    dp[i][j] = true;
                }
                if (j < cols && s3.charAt(i + j) == s2.charAt(j) && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }
}
