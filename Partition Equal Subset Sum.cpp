class Solution{
public:
    int equalPartition(int n, int a[]){
        int sum = 0; 
        for(int i = 0; i < n; i++)
            sum += a[i];
        if(sum % 2 != 0)
            return 0;
        
        int dp[sum/2 + 1]; memset(dp, 0, sizeof(dp));
        dp[0] = 1;
            
        for(int i = n - 1; i >= 0; i--){
            for(int target = sum/2; target >= 0; target--){
                if(target >= a[i])
                    dp[target] |= dp[target - a[i]];
            }
        }
        return dp[sum/2];
    }
};
