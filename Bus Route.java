class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        HashMap<Integer, ArrayList<Integer>> adjList = new HashMap<>();

        for (int i = 0; i < routes.length; i++) {
            for (int stop: routes[i]) {
                ArrayList<Integer> route = adjList.getOrDefault(stop, new ArrayList<>());
                route.add(i);
                adjList.put(stop, route);
            }
        }

        Queue<Integer> q = new LinkedList<>();
        Set<Integer> visited = new HashSet<Integer>(routes.length);

        for (int route : adjList.get(source)) {
            q.add(route);
            visited.add(route);
        }

        int busCount = 1;

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int route = q.remove();

                for (int stop: routes[route]) {
                    if (stop == target) {
                        return busCount;
                    }

                    for (int nextRoute: adjList.get(stop)) {
                        if (!visited.contains(nextRoute)) {
                            visited.add(nextRoute);
                            q.add(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
}
