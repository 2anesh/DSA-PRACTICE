class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length;
        int[] dist1 = new int[n];
        int[] dist2 = new int[n];
        Arrays.fill(dist1, Integer.MAX_VALUE);
        Arrays.fill(dist2, Integer.MAX_VALUE);
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        Boolean[] vis1 = new Boolean[n], vis2 = new Boolean[n];
        Arrays.fill(vis1, Boolean.FALSE);
        Arrays.fill(vis2, Boolean.FALSE);

        dfs(edges, node1, vis1, dist1);
        dfs(edges, node2, vis2, dist2);
        
        int minNode = -1, minDis = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            if(minDis>Math.max(dist1[i],dist2[i])){
                minNode = i;
                minDis = Math.max(dist1[i],dist2[i]);
            }
        }
        
        return minNode;
    }
    
    public static void dfs(int[] edges, int node, Boolean[] vis, int[] dist){
        vis[node] = true;
        
        int ni = edges[node];
        if(ni!=-1 && vis[ni]==false){
            dist[ni] = 1 + dist[node];
            dfs(edges, ni, vis, dist);
        }
    }
}
