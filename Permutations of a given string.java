class Solution {
   public static ArrayList<String> find_permutation(String S) {
        ArrayList<String> result = new ArrayList<>();
        char[] arr = S.toCharArray();
        int n = arr.length;
        Arrays.sort(arr); // Sort the array to get permutations in lexicographical order
        boolean[] visited = new boolean[n];
        StringBuilder sb = new StringBuilder();
        generatePermutations(arr, visited, sb, result);
        return result;
    }

    private static void generatePermutations(char[] arr, boolean[] visited, StringBuilder sb, ArrayList<String> result) {
        if (sb.length() == arr.length) {
            result.add(sb.toString());
            return;
        }

        for (int i = 0; i < arr.length; i++) {
            if (!visited[i]) {
                if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1])
                    continue; // Skip duplicates to avoid redundant permutations
                visited[i] = true;
                sb.append(arr[i]);
                generatePermutations(arr, visited, sb, result);
                sb.deleteCharAt(sb.length() - 1);
                visited[i] = false;
            }
        }
    }
}
