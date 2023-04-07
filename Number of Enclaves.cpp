class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // DFS or BFS on boundary cells
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1 && !visited[i][0]) {
                dfs(grid, visited, i, 0);
            }
            if(grid[i][n-1] == 1 && !visited[i][n-1]) {
                dfs(grid, visited, i, n-1);
            }
        }
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1 && !visited[0][j]) {
                dfs(grid, visited, 0, j);
            }
            if(grid[m-1][j] == 1 && !visited[m-1][j]) {
                dfs(grid, visited, m-1, j);
            }
        }
        
        // Count land cells that are not connected to the boundary
        int count = 0;
        for(int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visited[x][y]) {
                dfs(grid, visited, x, y);
            }
        }
    }
};
