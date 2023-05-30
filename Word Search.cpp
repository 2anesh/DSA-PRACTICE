class Solution {
public:
    bool dfs(vector<int> index, vector<vector<char>> &board, string word, int position, vector<vector<bool>> &vis ){          
        //base case
        if(position == word.size()){
            return true;
        }
        
        //recursive calls
        int nrow = board.size();
        int ncol = board[0].size();
        
        int r = index[0];
        int c = index[1];
        
        vis[r][c] = true;
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        for(int i=0; i<4; i++){
            int row = r + dx[i];
            int col = c + dy[i];
            if(row>=0 && row<nrow && col>=0 && col<ncol){
                if(board[row][col]==word[position] && !vis[row][col]){
                    if(dfs({row, col}, board, word, position+1, vis) == true){
                        return true;
                    }
                    //backtracking
                    vis[row][col] = false;
                }
            }
        }
        
        return false;
        
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        //find the index of the first character
        vector<int> index;
        bool done = false;
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]==word[0]){
                    //call dfs function form here
                    if(dfs({i, j}, board, word, 1, visited) == true){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
