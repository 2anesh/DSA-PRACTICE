class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        
        int dp = 0, half = -prices[0];
        for(int i=2;i<=n;i++){
            int prev_dp = dp;
            int prev_half = half;
            dp = max(dp,half+prices[i-1]);
            half = max(prev_half,prev_dp-prices[i-1]);
        }
        return dp;
    }
};
