class Solution {
    public Node construct(int[][] grid) {
        return dfs(grid,grid.length,0,0);
    }
    public Node dfs(int [][]grid,int n,int r,int c){
        boolean AllSame=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[r][c]!=grid[r+i][c+j]){
                    AllSame=false;
                    break;
                }
            }
        }
        if(AllSame){
            return new Node(grid[r][c]==1,true,null,null,null,null);
        }
        n=n/2;
        Node topLeft=dfs(grid,n,r,c);
        Node topRight=dfs(grid,n,r,c+n);
        Node bottomLeft=dfs(grid,n,r+n,c);
        Node bottomRight=dfs(grid,n,r+n,c+n);
        return new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);
    }
}
