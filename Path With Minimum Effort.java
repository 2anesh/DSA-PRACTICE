class Solution {
    public int minimumEffortPath(int[][] heights) {
        int rows = heights.length;
        int cols = heights[0].length;
        
        // Create a priority queue to store cells with minimum effort
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[2], b[2]));
        
        // Initialize the len matrix with maximum values
        int[][] len = new int[rows][cols];
        for (int[] row : len) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        
        // Directions for moving up, down, left, and right
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Add the starting cell to the priority queue
        pq.offer(new int[]{0, 0, 0});
        len[0][0] = 0;
        
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int row = curr[0];
            int col = curr[1];
            int effort = curr[2];
            
            // If we reached the bottom-right cell, return the effort
            if (row == rows - 1 && col == cols - 1) {
                return effort;
            }
            
            // Explore neighboring cells
            for (int[] dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int newEffort = Math.max(effort, Math.abs(heights[newRow][newCol] - heights[row][col]));
                    
                    if (newEffort < len[newRow][newCol]) {
                        pq.offer(new int[]{newRow, newCol, newEffort});
                        len[newRow][newCol] = newEffort;
                    }
                }
            }
        }
        
        // This should not happen if there is a valid path
        return -1;
    }
}
