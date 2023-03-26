class Solution {
public:
    void dfs(int u,vector<bool>& vis,vector<bool>& dfsvis,vector<int>& count,vector<int>& edges,int& ans){
        
        static int time = 0;
        time+=1;
        count[u] = time;
        vis[u] = true;
        dfsvis[u] = true;
        int v = edges[u];
        if(v == -1){
            dfsvis[u] = false;
            return;
        }
            
            if(vis[v] and dfsvis[v]){
                ans = max(ans,count[u]-count[v]);
                dfsvis[u] = false;
                return;
            }else if(!vis[v]){
                dfs(v,vis,dfsvis,count,edges,ans);
            }
        dfsvis[u] = false;
    }
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int n=edges.size();
        vector<bool> vis(n,false);
        vector<bool> dfsvis(n,false);
        vector<int> count(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i] and edges[i] != -1){
                dfs(i,vis,dfsvis,count,edges,ans);
            }
        }
        if(ans == -1)
            return -1;
        
        return ans+1;
    }
};
