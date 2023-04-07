class Pair{
    int row;
    int col;
    Pair(int row, int col){
        this.row = row;
        this.col = col;
    }
}
class Solution {
    public void dfs(int row, int col , int [][] grid, int [] lands){
        int N = grid.length;
        int M = grid[0].length;
        if(row < 0 || row == N || col< 0 || col == M || grid[row][col] == 0) return ;
        int [] delRow = {-1, 0, 1, 0};
        int [] delCol = {0, 1, 0, -1};
        grid[row][col] = 0;
        lands[0]++;
        for(int i=0; i< 4; i++){
            int Nrow = delRow[i] + row;
            int Ncol = delCol[i] + col;
            dfs(Nrow, Ncol, grid, lands);
        }
    }
    public int numEnclaves(int[][] grid) {
        int island = 0;
        int N = grid.length, M = grid[0].length;
        Queue<Pair> queue = new LinkedList<>();
        for(int i=0; i< N; i++){
            for(int j=0; j< M; j++){
                if(i == 0 || i == N-1 || j == 0 || j == M-1){
                    if(grid[i][j] == 1){
                        queue.add(new Pair(i, j));
                        grid[i][j] = 0;
                    }
                }
            }
        }
        int [] delRow = {-1, 0, 1, 0};
        int [] delCol = {0, 1, 0, -1};
        while(!queue.isEmpty()){
            Pair p = queue.remove();
            for(int i=0; i<4; i++){
                int nrow = delRow[i] + p.row;
                int ncol = delCol[i] + p.col;
                if(nrow >=0 && nrow < N && ncol >=0 && ncol < M && grid[nrow][ncol] == 1){
                    queue.add(new Pair(nrow, ncol));
                    grid[nrow][ncol] = 0;
                }
            }
        }
        for(int i=0; i< N; i++){
            for(int j=0; j< M; j++){
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
        for(int i=0; i< N; i++){
            for(int j=0; j< M; j++){
                if(grid[i][j] == 1){
                    int [] lands = {0};
                    dfs(i, j, grid, lands);
                    island += lands[0];
                }
            }
        }
        return island;
    }
}
