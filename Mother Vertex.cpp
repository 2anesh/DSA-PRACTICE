class Solution 
{
   
 private:
 
 void dfs(int vertex , vector<int>adj[] , vector<bool>&visited , stack<int>&stk)
 {
    visited[vertex] = true;
    for(auto node : adj[vertex])
    {
        if(!visited[node])
        {
            dfs(node,adj,visited,stk);
        }
    }
    stk.push(vertex);
 }


 bool allVisited(vector<bool>&vis)
 {
    for(int i=0;i<vis.size();i++)
    {
        if(vis[i] == false) return false;
    }
    return true;
 }

 public :

 int findMotherVertex(int V, vector<int>adj[])
 {
	    // Code here
        vector<bool>vis(V,false);
        stack<int>stk;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,stk);
        }
        
        int top = stk.top();
        
        for(int i=0;i<V;i++) vis[i] = false;
        
        dfs(top,adj,vis,stk);
        
        if(allVisited(vis)) return top;
        
        return -1;
 }
 
};
