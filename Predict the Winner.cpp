class Solution {
public:

    int f(int i,int j,bool player1,bool player2,vector<int>& nums,vector<vector<int>>& dp){

        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(player1){
            int maxfirst = 0;
            maxfirst = nums[i] + f(i+1,j,0,1,nums,dp);
            maxfirst = max(maxfirst,nums[j]+f(i,j-1,0,1,nums,dp));
            return dp[i][j] = maxfirst;
        }
        int minfirst = f(i+1,j,1,0,nums,dp)-nums[i];
        int minlast = f(i,j-1,1,0,nums,dp)-nums[j];
        
        return dp[i][j] = min(minfirst,minlast);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int res = f(0,n-1,1,0,nums,dp);
        return (res>=0)?true:false;
    }
};
