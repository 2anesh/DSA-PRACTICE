class Solution {
    public List<Integer> eventualSafeNodes(int[][] grid) {
        List<Integer> l = new ArrayList<>();
        int[] vis = new int[grid.length];
        
        for(int i=0; i<grid.length; i++){
            if(vis[i] == 0){
                help(grid, i, vis);
            }
        }
        for(int i=0; i<grid.length; i++){
            if(vis[i] != 2){
                l.add(i);
            }
        }
        return l;
    }

    public boolean help(int[][] grid, int i, int[] vis){
        //unvisited nodes - 0
        //visited nodes not in cyclic path - 1
        //visited nodes in the path of cycle - 2
        vis[i] = 2;
        for(int nbr: grid[i]){
            if(vis[nbr] == 2){
                return true;
            }
            if(vis[nbr] == 0){
                if(help(grid, nbr, vis)) return true;
            }
        }
        vis[i] = 1;
        return false;
    }
}
