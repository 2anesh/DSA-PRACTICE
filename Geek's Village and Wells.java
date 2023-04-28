class Solution
{
    public int[][] chefAndWells(int n,int m,char c[][])
    {
        int[] rowIndex = new int[] { -1, 0, 0, 1 };
        int[] colIndex = new int[] { 0, -1, 1, 0 };
        int[][] result = new int[c.length][c[0].length];
        Arrays.stream(result).forEach(arr -> Arrays.fill(arr, -1));
        boolean[][] visited = new boolean[c.length][c[0].length];
        Arrays.stream(visited).forEach(arr -> Arrays.fill(arr, false));
        Queue<int[]> queue = new LinkedList<>();
        queue.addAll(getStartingIndex(c, result, visited));
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            for (int i = 0; i < rowIndex.length; i++) {
                int row = current[0] + rowIndex[i];
                int col = current[1] + colIndex[i];
                if (row >= 0 && row < c.length && col >= 0 && col < c[row].length && (c[row][col] == 'H' || c[row][col] == '.') && !visited[row][col]) {
                    visited[row][col] = true;
                    result[row][col] = 1 + result[current[0]][current[1]];
                    queue.add(new int[] {row, col});
                }
            }
        }
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[i].length; j++) {
                if (result[i][j] != -1) {
                    result[i][j] *= 2;
                }
                if (c[i][j] == '.') {
                    result[i][j] = 0;
                }
            }
        }
        return result;
    }
    
    private List<int[]> getStartingIndex(char[][] ch, int[][] result, boolean[][] visited) {
        List<int[]> startingIndex = new ArrayList<>();
        for (int i = 0; i < ch.length; i++) {
            for (int j = 0; j < ch[i].length; j++) {
                if (ch[i][j] == 'W') {
                    result[i][j] = 0;
                    startingIndex.add(new int[] {i, j});
                    visited[i][j] = true;
                } else if (ch[i][j] == 'N') {
                    result[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }
        return startingIndex;
    }
}
