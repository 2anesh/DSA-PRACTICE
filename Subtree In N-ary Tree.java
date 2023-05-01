class Solution{
    public int duplicateSubtreeNaryTree(Node root){
       // Code here
       // Map to store the subtree string and its frequency
        Map<String, Integer> subtreeMap = new HashMap<>();

        // Traverse the tree in postorder and construct the subtree string for each node
        constructSubtreeString(root, subtreeMap);

        // Count the number of subtrees that have occurred more than once
        int count = 0;
        for (int freq : subtreeMap.values()) {
            if (freq > 1) {
                count++;
            }
        }

        // Return the count of duplicate subtrees
        return count;
    }

    private String constructSubtreeString(Node node, Map<String, Integer> subtreeMap) {
        StringBuilder sb = new StringBuilder();
        sb.append(node.data).append(":");

        List<String> childSubtrees = new ArrayList<>();
        for (Node child : node.children) {
            childSubtrees.add(constructSubtreeString(child, subtreeMap));
        }

        // Sort the child subtree strings in lexicographic order
        Collections.sort(childSubtrees);

        // Append the sorted child subtree strings to the parent subtree string
        for (String childSubtree : childSubtrees) {
            sb.append(childSubtree).append(",");
        }

        // Store the frequency of the subtree string in the map
        String subtreeString = sb.toString();
        subtreeMap.put(subtreeString, subtreeMap.getOrDefault(subtreeString, 0) + 1);

        // Return the subtree string of the current node
        return subtreeString;
    }
    
}
