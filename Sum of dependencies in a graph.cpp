class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        // code here
        int ans=0;
        for(int i=0;i<V;i++)ans+=adj[i].size();
        return ans;
    }
};
