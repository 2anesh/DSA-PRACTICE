class Solution
{
    public int closedIslands(int[][] grid, int n, int m)
    {
        // Code here
     // traversing boundary and converting 0s to 1s
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        dfs(i,j,n,m,grid);
                    }
                }
            }
        }
        //call DFS in whole grid and count surrounded land
        int count=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                count++;
                        dfs(i,j,n,m,grid);
                    }
                 }
            }
            return count;
    }
    public void dfs(int i,int j,int n,int m,int arr[][]){
        arr[i][j]=0;
        int ax[]={1,-1,0,0};
        int ay[]={0,0,1,-1}; 
        for(int k=0;k<4;k++){
            int nx=i+ax[k];
            int ny=j+ay[k];

            if(isValid(nx,ny,n,m,arr)){
                dfs(nx,ny,n,m,arr);
            }
        }
    }
    boolean isValid(int i,int j,int n,int m,int arr[][]){
        if(i>=0 && i<n && j>=0 && j<m && arr[i][j]==1) 
        return true;

        return false;
    }    
}
