class Solution {
    private class Edge {
        public int from;
        public int to;
        public int color;
    
        public Edge(int from, int to, int color) {
            this.from = from;
            this.to = to;
            this.color = color; // 0 is red. 1 is blue.
        }
    }
    
    private class Entry {
        public int node;
        public int colorTaken;
    
        public Entry(int node, int colorTaken) {
            this.node = node;
            this.colorTaken = colorTaken;
        }
        
        @Override
        public int hashCode() {
            return node * 1000 + colorTaken;
        }
        
        @Override
        public boolean equals(Object other) {
            if (!(other instanceof Entry)) {
                return false;
            }
            
            Entry that = (Entry) other;
            
            return this.node == that.node && this.colorTaken == that.colorTaken;
        }
    }
    
    public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
        List<Edge>[] graph = buildGraph(n, red_edges, blue_edges);
        
        int[] dists = new int[n];
        for (int i = 0; i < n; i++) {
            dists[i] = Integer.MAX_VALUE;
        }
        
        Deque<Entry> q = new ArrayDeque<>();
        Set<Entry> seen = new HashSet<>();
        
        q.addFirst(new Entry(0, 0));
        q.addFirst(new Entry(0, 1));
        seen.add(new Entry(0, 0));
        seen.add(new Entry(0, 1));

        int dist = 0;
        
        while (q.size() > 0) {
            int size = q.size();
    
            for (int i = 0; i < size; i++) {
                Entry entry = q.removeLast();
                int val = entry.node;
                int nextColor = 1 - entry.colorTaken;

                dists[val] = Math.min(dists[val], dist);
                
                for (Edge e : graph[val]) {
                    if (e.color == nextColor) {
                        Entry nextEntry = new Entry(e.to, nextColor);
                        if (!seen.contains(nextEntry)) {
                            seen.add(nextEntry);
                            q.addFirst(nextEntry);
                        }
                    }
                }
            }
            
            dist++;
        }
        
        
        for (int i = 0; i < n; i++) {
            if (dists[i] == Integer.MAX_VALUE) {
                dists[i] = -1;                
            }
        }
        
        return dists;
    }
    
    private List[] buildGraph(int n, int[][] red_edges, int[][] blue_edges) {
        List<Edge>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int[] edge : red_edges) {
            int from = edge[0];
            int to = edge[1];
            
            graph[from].add(new Edge(from, to, 0));
        }
        
        for (int[] edge : blue_edges) {
            int from = edge[0];
            int to = edge[1];
            
            graph[from].add(new Edge(from, to, 1));
        }
        
        return graph;
    }
}
