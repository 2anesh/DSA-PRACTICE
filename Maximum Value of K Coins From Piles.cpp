class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> seen(piles.size(), vector<int>(k+1, -1)); 
        
        function<int(int, int)> fn = [&](int i, int k) {
            if (i == piles.size()) return 0; 
            if (k == 0) return 0; 
            if (seen[i][k] == -1) {
                seen[i][k] = fn(i+1, k); 
                int prefix = 0; 
                for (int j = 0; j < piles[i].size() && j < k; ++j) {
                    prefix += piles[i][j]; 
                    seen[i][k] = max(seen[i][k], prefix + fn(i+1, k-j-1)); 
                }
            }
            return seen[i][k]; 
        }; 
        
        return fn(0, k); 
    }
};
