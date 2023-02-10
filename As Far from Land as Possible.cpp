class Solution {
public:
    bool vis[101][101];
    int dis[101][101];
    queue<pair<int,int>>q;
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        //memset(vis,false,sizeof(vis));
        //memset(dis,1000,sizeof(dis));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vis[i][j]=false;
                dis[i][j]=1000;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)q.push({i,j}),dis[i][j]=0,vis[i][j]=true;
                else dis[i][j]=1000;
            }
        }
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int i=p.first,j=p.second;
            if(i+1<n&&j<n&&(dis[i+1][j]>1+dis[i][j])&&!vis[i+1][j])
            {
                dis[i+1][j]=dis[i][j]+1;
                vis[i+1][j]=true;
                q.push({i+1,j});
            }
            if(i-1>=0&&j<n&&(dis[i-1][j]>1+dis[i][j])&&!vis[i-1][j])
            {
                dis[i-1][j]=dis[i][j]+1;
                vis[i-1][j]=true;
                q.push({i-1,j});
            }
            if(i<n&&j+1<n&&(dis[i][j+1]>1+dis[i][j])&&!vis[i][j+1])
            {
                dis[i][j+1]=dis[i][j]+1;
                vis[i][j+1]=true;
                q.push({i,j+1});
            }
            if(i<n&&j-1>=0&&(dis[i][j-1]>1+dis[i][j])&&!vis[i][j-1])
            {
                dis[i][j-1]=dis[i][j]+1;
                vis[i][j-1]=true;
                q.push({i,j-1});
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,dis[i][j]);
            }
        }
        if(ans==0||ans==1000)
        {
            return -1;
        }
        return ans;
    }
};
