class Solution {
    public int[] restoreArray(int[][] adjacentPairs) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        
        for (int[] pair : adjacentPairs) {
            adjList.computeIfAbsent(pair[0], k -> new ArrayList<>()).add(pair[1]);
            adjList.computeIfAbsent(pair[1], k -> new ArrayList<>()).add(pair[0]);
        }
        
        int n = adjacentPairs.length + 1;
        int[] result = new int[n];
        
        for (Map.Entry<Integer, List<Integer>> entry : adjList.entrySet()) {
            if (entry.getValue().size() == 1) {
                result[0] = entry.getKey();
                break;
            }
        }
        
        result[1] = adjList.get(result[0]).get(0);
        
        for (int i = 2; i < n; i++) {
            List<Integer> list = adjList.get(result[i - 1]);
            result[i] = result[i - 2] == list.get(0) ? list.get(1) : list.get(0);
        }
        
        return result;
    }
}
