class Solution {
    int m;
    int n;

    public int closedIsland(int[][] grid) {
        this.m = grid.length;
        this.n = grid[0].length;

        // Do a floodFill from only the four corners of the grid.
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 || row == m - 1 || col == 0 || col == n - 1) {
                    fill(row, col, grid);
                    
                }
            }
        }

        int result = 0;
        // If you find a 0 (land) increase count and replace it with 0 (water)
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    result++;
                    dfs(row, col, grid);
                }
            }
        }

        return result;
    }

    private void dfs(int i, int j, int[][] grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) return;
        grid[i][j] = 1;

        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }

    private void fill(int i, int j, int[][] grid) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (grid[i][j] == 1) return;
        grid[i][j] = 1;

        fill(i-1, j, grid);
        fill(i+1, j, grid);
        fill(i, j+1, grid);
        fill(i, j-1, grid);
    }
}
