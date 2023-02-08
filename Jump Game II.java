class Solution {
    public int jump(int[] nums) {
        int[] dp=new int[nums.length];
        Arrays.fill(dp,-1);
        int val=helper(nums,0,dp);
        return val;
    }
    public int helper(int[] nums,int i,int[] dp){
        if(i==nums.length-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=100000;
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.length){
                ans=Integer.min(ans,helper(nums,i+j,dp)+1);
            }
        }
        dp[i]=ans;
        return ans;
        
    }
}
