class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int sr=0,er=n-1,sc=0,ec=n-1;
        int k=1;
        while(k<=n*n){
            for(int i=sc;i<=ec;i++){
                matrix[sr][i]=k;
                k+=1;
            }
            sr+=1;
            for(int j=sr;j<=er;j++){
                matrix[j][ec]=k;
                k+=1;
            }
            ec-=1;
            for(int i=ec;i>=sc;i--){
                matrix[er][i]=k;
                k+=1;
            }
            er-=1;
            for(int j=er;j>=sr;j--){
                matrix[j][sc]=k;
                k+=1;
            }
            sc+=1;
        }
        return matrix;
    }
};
