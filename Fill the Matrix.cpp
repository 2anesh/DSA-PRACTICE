class Solution{   

public:

    bool isSafe(int i, int j, int N, int M){

        if(i<0 or j<0 or i>=N or j>=M) return false;

        return true;

    }

 

    int minIteration(int N, int M, int x, int y){    

        // code here

        vector<vector<int>> mat(N, vector<int>(M,0));

        mat[x-1][y-1] = 1;

        int dx[4] = {-1,1,0,0};

        int dy[4] = {0,0,-1,1};

        

        queue<pair<int,int>> q;

        q.push({x-1,y-1});

        int lvl = 0;

        

        while(!q.empty()){

            int s = q.size();

            for(int k=0; k<s; k++){

                int nx = q.front().first;

                int ny = q.front().second;

                q.pop();

                for(int i=0; i<4; i++){

                    int r = nx+dx[i];

                    int c = ny+dy[i];

                    if(isSafe(r,c,N,M) and !mat[r][c]){

                        mat[r][c] = 1;

                        q.push({r,c});

                    }

                }

            }

            if(!q.empty())

            lvl++;

        }

        return lvl;

    }

};
