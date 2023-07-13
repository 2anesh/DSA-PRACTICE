class Solution {
    public boolean canFinish(int V, int[][] B) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++){
            adj.add(new ArrayList<>());
        }
        for(int i = 0; i < B.length; i++){
            adj.get(B[i][0]).add(B[i][1]);
        }
        int[] vis= new int[V];
        //int[] path= new int[V];
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,vis,adj)){
                    return false;
                }
            }
        }
        return true;
    }
    private boolean dfs(int node,int[] vis,List<List<Integer>> adj){
        vis[node]=1;
        //path[node]=1;
        for(int i:adj.get(node)){
            if(vis[i]==0){
                if(dfs(i,vis,adj)){
                    return true;
                }
               
            }
            else if(vis[i]==1){
                return true;
            }
        }
        vis[node]=2;
        return false;
    }
}
