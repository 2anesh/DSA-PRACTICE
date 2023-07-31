class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
   vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> res;
    vector<bool> vst(V);
    vst[0] = 1;
    res.push_back(0);
    int i = 0, n = 0;
    while(res.size() != n){
        n = res.size();
        while(i < n){
            for(auto u: adj[res[i]]){
                if(!vst[u]){
                    vst[u] = 1;
                    res.push_back(u);
                }
            }
            i++;
        }
    }
    return res;
}
};
