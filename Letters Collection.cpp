class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>>& mat, int q, vector<int> que[]){
        vector<int>ans;
        for(int i=0;i<q;i++){
            int op=que[i][0],x=que[i][1],y=que[i][2],val=0;
            for(int dx=-op;dx<=op;dx++){
                for(int dy=-op;dy<=op;dy++){
                    if(dx==op || dx == -op || dy==op || dy==-op){
                        int nx=x+dx, ny=y+dy;
                        if(nx>=0 && nx<n && ny>=0 && ny<m ) val+=mat[nx][ny];
                    }
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};
