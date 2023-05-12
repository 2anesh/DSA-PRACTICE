class Solution {
    public long mostPoints(int[][] questions) {
        int s=questions.length;
        long[] dp = new long[s];
        dp[s-1]=questions[s-1][0];
        for(int i=s-2;i>=0;i--){
            int nqp = i+questions[i][1]+1;
            dp[i] = Math.max(questions[i][0]+(nqp>=s ? 0:dp[nqp]),dp[i+1]);
        }
        return dp[0];
    }
}
