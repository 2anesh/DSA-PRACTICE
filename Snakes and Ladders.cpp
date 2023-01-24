class Solution {
public:
    vector<int> findCoordinates(int n,int position) {    // function to get cell coordinates
        vector<int> ans(2);
        int r= n-(position-1)/n-1;
        int c=(position-1)%n;
        if(r%2==n%2) {    // since there is a reversal in cell position after every row,
            c=n-c-1;     // this check will take care of that
        }
        ans[0]=r;
        ans[1]=c;
        return ans;
}


int snakesAndLadders(vector<vector<int> >& board) {
        int n=board.size();
        vector<vector<bool> > visited(n,vector<bool>(n,false));
        queue<pair<int,int> > q;
        q.push(make_pair(1,0));
        visited[n-1][0]=true;
        while(!q.empty()) {
				int currPos=q.front().first;
                int steps=q.front().second;
                q.pop();
                if(currPos==n*n) {
                    return steps;
                }

                for(int i=1;i<=6;i++) {
                    int nextPos=currPos+i;
                    if(nextPos>n*n) break;
                    vector<int> temp= findCoordinates(n,nextPos);
                    int r=temp[0];
                    int c=temp[1];
                    if(!visited[r][c]) {
                        visited[r][c]=true;
                        if(board[r][c]!=-1) {
                            q.push(make_pair(board[r][c],steps+1));
                        }
                        else {
                            q.push(make_pair(nextPos,steps+1));
                        }
                    }

                }
            
            
        }
        return -1;
        
        
	}

};
