public class Solution {
    
    long fuel = 0;
    
    public long minimumFuelCost(int[][] roads, int seats) {
        List<List<Integer>> graph = new ArrayList<>();
        fuel = 0;
        for (int i = 0; i <= roads.length; i++) graph.add(new ArrayList<>());
        for (int i = 0; i < roads.length; i++) {
            graph.get(roads[i][0]).add(roads[i][1]);
            graph.get(roads[i][1]).add(roads[i][0]);
        }
        
        dfs(graph, seats, 0, 0);
        
        return fuel;    
    }
    
    private int dfs(List<List<Integer>> graph, int seats, int prev, int cur) {
        int people = 1;
        int incoming = 0;
        for (int city: graph.get(cur)) {
            if (city != prev) {
                incoming = dfs(graph, seats, cur, city);
                fuel += (incoming % seats == 0) ? incoming / seats : ( incoming / seats ) + 1;
                people += incoming;
            }
        }
        
        return people;
    }
}
