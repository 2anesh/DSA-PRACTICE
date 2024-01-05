class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int p = nums.length;
        int[] dp = new int[p];
        dp[0] = 1;
        int maxLength = 1;
        for (int k = 1; k < p; k++) {
            dp[k] = 1; 
            for (int l = 0; l < k; l++) {
                if (nums[k] > nums[l]) {
                    dp[k] = Math.max(dp[k], dp[l] + 1);
                }
            }
            maxLength = Math.max(maxLength, dp[k]);
        }
        return maxLength;
    }
}
