class Solution{
    bool check(int x , int y , int r , int c){
        if(x < 0 || x >= c || y < 0 || y >= r)
            return false;
        return true;
    }
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int r, int c){
        int iterx = 0 , itery = 0 , dr = 0;
        int dry[] = {0 , 1 , 0 , -1};
        int drx[] = {1 , 0 , -1 , 0};
        while(check(iterx , itery , r , c)){
            if(matrix[itery][iterx]){
                dr = (dr + 1) % 4;
                matrix[itery][iterx] = 0;
            }
            iterx += drx[dr];
            itery += dry[dr];
        }
        return {itery - dry[dr] , iterx - drx[dr]};
    }
};
