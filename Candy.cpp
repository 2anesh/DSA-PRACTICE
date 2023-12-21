class Solution {
    void dfs(int s, vector<vector<int>> &adj, vector<int> &vis, vector<int> &candies)
    {
        vis[s] = 1;
        for(auto &it: adj[s])
        {
            candies[it] = max(candies[it], candies[s]+1);
            dfs(it, adj, vis, candies);
        }
    }
  public:
    int minCandy(int n, vector<int> &ratings) {
        // code here
        vector<vector<int>> adj(n);
        for(int i = 1; i<n; i++)
        {
            if(ratings[i-1] > ratings[i])adj[i].push_back(i-1);
            else if(ratings[i-1] < ratings[i])adj[i-1].push_back(i);
        }
        
        vector<int> vis(n, 0);
        vector<int> candies(n, 1);
        for(int i = 0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis, candies);
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
