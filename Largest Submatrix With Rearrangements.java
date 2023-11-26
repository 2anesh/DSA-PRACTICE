class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length, max = 0;
        int [][] onceCount = new int[m][n];
        for (int i = 0; i < n; i++){
            onceCount[0][i] = matrix[0][i];
            for (int j = 1; j < m; j++) if (matrix[j][i] == 1) onceCount[j][i] = onceCount[j - 1][i] + 1;
        }
        for (int j = 0; j < m; j++) {
            PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b - a);
            for (int i = 0; i < n; i++) if (onceCount[j][i] > 0) pq.offer(onceCount[j][i]);
            int cols = 0;
            while (!pq.isEmpty()) max = Math.max(max , pq.poll() * ++cols);
        }
        return max;
    }
}
