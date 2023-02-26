class Solution {
    public int findNumberOfGoodComponent(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        boolean vis[]=new boolean[V+1];
        int cntcomp=0;
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                int cnt[]=new int[1];
                int cntedge[]=new int[1];
                dfs(i,vis,adj,cnt,cntedge);
                if(cntedge[0]/2==(cnt[0]*(cnt[0]-1))/2){
                    cntcomp++;
                }
            }
        }
        return cntcomp;
    }
    public void dfs(int node,boolean vis[],ArrayList<ArrayList<Integer>> adj,int[] cnt,int[] cntedge){
        vis[node]=true;
        cnt[0]++;
        for(int adjnode:adj.get(node)){
            cntedge[0]++;
            if(!vis[adjnode]){
                dfs(adjnode,vis,adj,cnt,cntedge);
            }
        }
    }
}
