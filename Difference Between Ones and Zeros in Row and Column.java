class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int ones_rowsum[]=new int[grid.length];
        int ones_colsum[]=new int[grid[0].length];
        int zeros_rowsum[]=new int[grid.length];
        int zeros_colsum[]=new int[grid[0].length];
        int diff[][]=new int[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                ones_rowsum[i]+=grid[i][j];
                ones_colsum[j]+=grid[i][j];
                zeros_rowsum[i]+=1-grid[i][j];
                zeros_colsum[j]+=1-grid[i][j];
            }
        }
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                diff[i][j]=ones_rowsum[i]+ones_colsum[j]-zeros_rowsum[i]-zeros_colsum[j];
            }
        }
        return diff;
    }
}
