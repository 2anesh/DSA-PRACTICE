class Solution {
public:
    
    int minSum(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m-1 and j == n-1) return grid[i][j];
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int option1 = INT_MAX, option2 = INT_MAX;
        if(i + 1 < m){
          option1 = minSum(grid, m, n, i+1, j, dp);  
        }
        if(j + 1 < n){
             option2 = minSum(grid, m, n, i, j+1, dp);
        }
        int ans = grid[i][j] + min(option1, option2);
        dp[i][j] = ans;
        return ans;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minSum(grid, m, n, 0, 0, dp);
    }
}; 
