class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
           int c=0,n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int t=0;
                    if((i-1)>=0 && matrix[i-1][j]==0)t++;
                    if((i+1)< n && matrix[i+1][j]==0)t++;
                    if((j-1)>=0 && matrix[i][j-1]==0)t++;
                    if((j+1)< m && matrix[i][j+1]==0)t++;
                    if((i-1)>=0 && (j-1)>=0 && matrix[i-1][j-1]==0)t++;
                    if((i+1)< n && (j-1)>=0 && matrix[i+1][j-1]==0)t++;
                    if((i+1)< n && (j+1)<m && matrix[i+1][j+1]==0)t++;
                    if((i-1)>=0 && (j+1)<m && matrix[i-1][j+1]==0)t++;
                    if(t!=0 && t%2==0)c++;
                }
            }
        }
        return c;
    }
};
