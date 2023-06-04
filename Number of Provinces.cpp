class Solution {
    private:
    void dfs(int node, vector<int> isConnectedls[], int vis[])
    {
      vis[node]=1;
      for(auto it: isConnectedls[node])
      {
          if(!vis[it])
          {
              dfs(it,isConnectedls,vis);
          }
      }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> isConnectedls[n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j] == 1 && i != j) {
                    isConnectedls[i].push_back(j); 
                    isConnectedls[j].push_back(i);
            }
            
        }
    }
     int vis[1000000] = {0}; 
        int cnt = 0; 
        for(int i = 0;i<n;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, isConnectedls, vis); 
            }
        }
        return cnt; 
        
    }
};
