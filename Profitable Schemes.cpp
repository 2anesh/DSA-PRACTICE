class Solution {
public:
   const int MOD = 1e9 + 7;

int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int m = group.size();
    vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int k = 0; k < m; k++) {
        for (int i = minProfit; i >= 0; i--) {
            for (int j = n - group[k]; j >= 0; j--) {
                int newProfit = min(i + profit[k], minProfit);
                dp[newProfit][j + group[k]] = (dp[newProfit][j + group[k]] + dp[i][j]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + dp[minProfit][i]) % MOD;
    }
    return ans;
}

};
