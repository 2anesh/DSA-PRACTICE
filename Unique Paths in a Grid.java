class Solution {
    static int uniquePaths(int n, int m, int[][] grid) {
        // code here

        int[] t=new int[m];
        int maxi=1000000007;
        
        for(int i=m-1;i>=0;i--){
            if(grid[n-1][i]==0){
                break;
            }
            t[i]=1;
        }
        
        
        for(int i=n-2;i>=0;i--){
            int[] temparr=new int[m];
            for(int j=m-1;j>=0;j--){
                
                if(j==m-1){
                    temparr[j]=(grid[i][j]*(t[j]%maxi));
                }
                else{
                    temparr[j]=(grid[i][j]*(((t[j]%maxi)+(temparr[j+1]%maxi))%maxi));
                }
                
            }
            t=temparr;
        }
        return t[0];
    }
};
