class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            // out of grid
            return false;
        }
        if (grid[i][j] == 1) {
            // here we r already visited or water
            return true;
        }
        grid[i][j] = 1; // mark as visited
        bool left = dfs(grid, i, j - 1);
        bool right = dfs(grid, i, j + 1);
        bool up = dfs(grid, i - 1, j);
        bool down = dfs(grid, i + 1, j);
        return left && right && up && down;
    }
};
