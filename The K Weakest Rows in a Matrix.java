class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[] count = new int[mat.length];
        // Count 1s according to row
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                if (mat[i][j] == 1) {
                    count[i]++;
                } else {
                    break;
                }
            }
        }

        // Create an array to store the answer
        Integer[] indices = new Integer[mat.length];
        for (int i = 0; i < mat.length; i++) {
            indices[i] = i;
        }

        // Sort indices array based on counts and maintain the original order
        Arrays.sort(indices, (a, b) -> {
            if (count[a] != count[b]) {
                return count[a] - count[b];
            } else {
                return a - b; // Maintain the original order in case of ties
            }
        });

        // Create the result array with the first k weakest rows
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = indices[i];
        }

        return result;
    }
}
