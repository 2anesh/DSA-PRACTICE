class Solution 
{
 public: 
    int minReorder(int n, vector<vector<int>>& nums) 
    {
          vector<int>adj[n];
          set<pair<int,int>>st;
          for(int i=0;i<nums.size();i++)
          {
              st.insert({nums[i][0],nums[i][1]});
              adj[nums[i][0]].push_back(nums[i][1]);
              adj[nums[i][1]].push_back(nums[i][0]);
          }
          queue<int>q;
          q.push(0);
          int ans=0;
          vector<bool>vis(n,false);
          while(!q.empty())
          {
              int x=q.front();
              q.pop();
              if(!vis[x])
              {
                   vis[x]=true;   
                   for(int i:adj[x])
                   {
                       q.push(i);
                       if(!vis[i] && st.count({x,i}))
                          ans++;
                   }
              }
          }
        return ans;
    }
};
