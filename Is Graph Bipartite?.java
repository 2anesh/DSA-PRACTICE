class Solution {
    public boolean bipara(int[]color, int[][]graph, int node){
        Queue<Integer>q = new LinkedList<Integer>();
            q.add(node);
        color[node] = 1;
        while(!q.isEmpty()){
            int n = q.poll();
            for(int j:graph[n]){
                if(color[j]==-1){
                    color[j] = 1-color[n];
                    q.add(j);
                }else if(color[j]==color[n]) return false;
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int[]color = new int[graph.length];
        Arrays.fill(color,-1);
        for(int i =0;i<graph.length;i++){
            if(color[i]==-1){
                if(!bipara(color,graph,i)) return false;
            }
        }
        return true;
    }
}
