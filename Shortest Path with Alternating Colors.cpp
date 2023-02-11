class Solution {
public:
    vector<int> gr[105], gb[105];
    int vis[105][2], dis[105];
    
    void bfs() {
        vis[0][0] = 1;
        vis[0][1] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        int ans = 0;
        while (q.size()) {
            int len = q.size();
            while(len--) {
                int u = q.front().first;
                int uc = q.front().second;
                q.pop();
                if (dis[u] == -1) dis[u] = ans;
                auto g = uc ? gb : gr;
                int vc = uc ?  0 : 1;
                for(auto v: g[u]) {
                    if(!vis[v][vc]) {
                        vis[v][vc] = 1;
                        q.push({v, vc});
                    }
                }
            }
            ans++;
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        for(auto x: redEdges) gr[x[0]].push_back(x[1]);
        for(auto x: blueEdges) gb[x[0]].push_back(x[1]);

        memset(dis, -1, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        bfs();

        vector<int> ans;
        for(int i=0; i<n; i++) ans.push_back(dis[i]);
        return ans;
    }
};
