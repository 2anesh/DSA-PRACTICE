class Solution {

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high + 1);
        int MOD = 1000000007;

        for(int i = high; i >= 0; i--)
        {
            dp[i] = i >= low ? 1 : 0;
            dp[i] = (dp[i] + (i + zero <= high ? dp[i + zero] : 0)) % MOD;
            dp[i] = (dp[i] + (i + one <= high ? dp[i + one] : 0)) % MOD;
        }

        return dp[0];
    }
};
