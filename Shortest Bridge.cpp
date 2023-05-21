class Solution {
    class State {
        int row;
        int col;
        int step;

        State(int row, int col, int step) {
            this.row = row;
            this.col = col;
            this.step = step;
        }
    }  

    int[][] directions = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public int shortestBridge(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] seen = new boolean[m][n];
        Queue<State> q = new LinkedList<>();


        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    // Add all 1s or island to seen.
                    dfs(row, col, grid, q, seen);

                    // Perform bfs from the first 1 we see.
                    return bfs(row, col, grid, q, seen);
                }
            }
        }

        // This prevent function from raising error
        return -1;
    }

    int bfs(int row, int col, int[][] grid, Queue<State> q, boolean[][] seen) {
        while(!q.isEmpty()) {
            State state = q.poll();

            for (int[] direction : directions) {
                int nextRow = direction[0] + state.row, nextCol = direction[1] + state.col;

                if ( valid(nextRow, nextCol, grid) && !seen[nextRow][nextCol] && grid[nextRow][nextCol] == 1) {
                        return state.step;
                    }

                if (valid(nextRow, nextCol, grid) && !seen[nextRow][nextCol]) {
                        seen[nextRow][nextCol] = true;
                        q.offer(new State(nextRow, nextCol, state.step + 1));
                    }
            }
        }
        return - 1;
    }

    void dfs(int row, int col, int[][] grid, Queue<State> q, boolean[][] seen) {
        if (inValid(row, col, grid) || grid[row][col] == 0 || seen[row][col]) {
            return;
        }

        // Add all 1s of the first island to seen and to the queue
        seen[row][col] = true;
        q.offer(new State(row, col, 0));

        // Go all directions
        for (int[] direction : directions) {
            int nextRow = direction[0] + row, nextCol = direction[1] + col;
            dfs(nextRow, nextCol, grid, q, seen);
        }
    }
    
    boolean inValid(int row, int col, int[][] grid) {
        return row < 0 || row >= grid.length || col < 0 || col >= grid[0].length;
    }

    boolean valid(int row, int col, int[][] grid) {
        return row >= 0 && row < grid.length && col >= 0 && col < grid[0].length;
    }
}
