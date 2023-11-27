class disjoint{
     vector<int> rank,par;
    public:
    disjoint(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int findpar(int node){
        if(node==par[node]){
            return node;
        }
        return par[node]=findpar(par[node]);
    }
 
     void unionrank(int u,int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
 
        if(ulp_u==ulp_v)return;
         if(rank[ulp_u]<rank[ulp_v]){
            par[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            par[ulp_v]=ulp_u;
        }
        else{
            par[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
 
 
 
 
 
};
class Solution
{
    public:
    
    //Function to detect cycle using DSU in an undirected graph.
int detectCycle(int v, vector<int>adj[])
{
    // Code here
    set<pair<int,int>> s;
    
    disjoint ds(v);
    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            if(s.find({i,adj[i][j]})!=s.end() or s.find({adj[i][j],i})!=s.end()){
                continue;
            }
            s.insert({i,adj[i][j]});
            int u=ds.findpar(i);
            int v=ds.findpar(adj[i][j]);
            if(u==v)return 1;
            ds.unionrank(i,adj[i][j]);
        }
    }
    return 0;
    
}
};
