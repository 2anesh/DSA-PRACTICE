class Solution {
    long long ans=0;
public:
    long long dfs(vector<vector<int>>& roads, int seats,vector<int>*adj,int src,int p)
    {
        long long  count =1;
        for(auto x:adj[src])
        {
            if(x!=p)
            count+=dfs(roads,seats,adj,x,src);
        }
        if(count%seats!=0)
        ans+=(count/seats)+1;
        else ans+=count/seats;
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<int>adj[roads.size()+1];
        int n=roads.size();
     using ll=long long;
        for(auto &x:roads)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        ll res=0;
        for(auto x:adj[0])
        {
           long long a= dfs(roads,seats,adj,x,0);
           res+=ans;
           ans=0;
        }
    return res;
    }
};
