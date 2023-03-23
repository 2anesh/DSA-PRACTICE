class Solution {
public:
    
  //check for redundent edges and number of components and use the formula to check for required number of operations 
    
    void dfs(unordered_map<int,vector<int>>& adj,vector<int>& vis, int node){
        vis[node]=1;
        for( auto it: adj[node]){
            if(vis[it] == -1){
                dfs(adj,vis,it);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int edges=0;
        vector<int> vis(n,-1);
        unordered_map<int,vector<int>> adj;
        
        for( int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }
        
        int components = 0;
        for( int i=0;i<n;i++){
            if(vis[i]== -1){
                components++;
                dfs(adj,vis,i);
            }
        }
        
        if(edges <n-1) return -1;
        
        
        int redendencyCheck = edges - (n-1 - (components-1));
    if(redendencyCheck >=components-1) return components-1;
                                       return -1;
                                       
    }
};
