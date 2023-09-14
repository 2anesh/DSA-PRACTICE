class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, PriorityQueue<String>> graph = new HashMap<>();
        List<String> itinerary = new ArrayList<>();

        // Build the graph from the given tickets.
        for (List<String> ticket : tickets) {
            String from = ticket.get(0);
            String to = ticket.get(1);
            graph.computeIfAbsent(from, k -> new PriorityQueue<>()).offer(to);
        }

        // Perform a depth-first search starting from JFK.
        dfs(graph, "JFK", itinerary);

        // Reverse the itenerary to get the correct order.
        Collections.reverse(itinerary);
        return itinerary;
    }

    private void dfs(Map<String, PriorityQueue<String>> graph, String airport, List<String> itinerary) {
        PriorityQueue<String> neighbors = graph.get(airport);

        while (neighbors != null && !neighbors.isEmpty()) {
            String nextAirport = neighbors.poll();
            dfs(graph, nextAirport, itinerary);
        }

        // Add the current airport to the itinerary.
        itinerary.add(airport);
    }
}
