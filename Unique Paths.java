class Solution {
    public int uniquePaths(int m, int n) {
        return dfs(m-1,n-1);
    }
    public int dfs(int x, int y){
        if(x==0 && y== 0)
            return 1;
        
        if(x>0 && y>0)
            return dfs(x-1,y)+ dfs(x,y-1);
        
        if(x>0)
            return dfs(x-1,y);
        if(y>0)
            return dfs(x,y-1);
        return 0;
    }
}
