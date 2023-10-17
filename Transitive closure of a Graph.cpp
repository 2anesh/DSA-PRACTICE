class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> grid)
    {
        
        for(int via = 0 ; via < N ; via++){
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N ; j++){
                    if( i == j) grid[i][j] = 1;
                    if(grid[i][j] == 0){
                        if(grid[i][via] == 1 && grid[via][j] == 1) grid[i][j] = 1;
                    }
                }
            }
        }
        
        return grid;
    }
};
