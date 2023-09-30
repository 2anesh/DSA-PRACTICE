class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        unordered_map<int,int> row,col;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(auto x:row){
            int i = x.first;
            for(int j=0;j<m;j++)
                matrix[i][j] = 1;
        }
        
        for(auto x:col){
            int j = x.first;
            for(int i=0;i<n;i++)
                matrix[i][j] = 1;
        }
    }

};
