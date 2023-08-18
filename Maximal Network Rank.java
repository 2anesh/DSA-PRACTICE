class Solution {
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        for(auto &road : roads){
          int u=road[0];
          int v=road[1];
          degree[u]++;
          degree[v]++;
          connected[u][v]=true;
          connected[v][u]=true;
        }
        int maxRank=0;
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            int i_rank=degree[i];
            int j_rank=degree[j];
            int rank=i_rank+j_rank;
            if(connected[i][j]){
              rank--;
            }
            maxRank=max(maxRank, rank);
          }
        }
        return maxRank;
    }
};
class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
      if(n<=1){
        return 0;
      }
      int[] degree = new int[n];
      int[][] connected = new int[n][n];
      for(int[] road : roads){
        int u=road[0], v=road[1];
        degree[u]++;
        degree[v]++;
        connected[u][v]=1;
        connected[v][u]=1;
      }
      int res=0;
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          int rank=degree[i]+degree[j]-connected[i][j];
          res=Math.max(res, rank);
        }
      }
      return res;
    }
}
