class Solution {
    int max=-1;
    public int longestCycle(int[] edges) {
        boolean vis[]=new boolean[edges.length];
       
        for(int i:edges)
        {  if(i==-1||vis[i]) continue;
           HashMap<Integer,Integer> map=new HashMap<>();
           dfs(i,0,vis,map,edges);
        }
        return max;
    }
    public void dfs(int node,int dis,boolean[]vis, HashMap<Integer,Integer> map,int []edges)
    {
        if(node==-1) return ;
        if(vis[node])
        {   
            if(!map.containsKey(node)) return ;
            max=Math.max(dis-map.get(node),max);
            //System.out.println(max);
            return ;
        }
        vis[node]=true;
        map.put(node,dis);
        dfs(edges[node],dis+1,vis,map,edges);
        return ;
         
    }
}
