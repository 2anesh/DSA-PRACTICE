class Solution {
    Map<TreeNode, List<TreeNode>> map = new HashMap();
    // Define a map to store the parent-child mapping of TreeNodes
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> res = new ArrayList<Integer> ();
        // Create a list to store the result
        
        if (root == null || K < 0) return res;
        // If the root is null or the given distance K is negative, return an empty list
        
        buildMap(root, null); 
        // Build the parent-child mapping for all nodes in the tree
        
        if (!map.containsKey(target)) return res;
        // If the target node is not present in the tree, return an empty list
        
        Set<TreeNode> visited = new HashSet<TreeNode>();
        // Create a set to keep track of visited nodes
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        // Create a queue for breadth-first search traversal
        
        q.add(target);
        visited.add(target);
        // Add the target node to the queue and mark it as visited
        
        while (!q.isEmpty()) {
            int size = q.size();
            // Get the current size of the queue (number of nodes at the current level)
            
            if (K == 0) {
                for (int i = 0; i < size ; i++)
                    res.add(q.poll().val);
                // If the distance K becomes zero, add all nodes at this level to the result and return
                
                return res;
            }
            
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                // Remove the node at the front of the queue
                
                for (TreeNode next : map.get(node)) {
                    if (visited.contains(next)) continue;
                    // Iterate through the children of the current node
                    
                    visited.add(next);
                    q.add(next);
                    // Add the child to the queue and mark it as visited
                }
            }
            
            K--;
            // Decrement the distance K after exploring each level
        }
        
        return res;
        // Return the result
    }
    
    private void buildMap(TreeNode node, TreeNode parent) {
        if (node == null) return;
        // Base case: If the node is null, return
        
        if (!map.containsKey(node)) {
            map.put(node, new ArrayList<TreeNode>());
            // If the node is not present in the map, add it with an empty list
            
            if (parent != null) {
                map.get(node).add(parent);
                map.get(parent).add(node);
                // Add the parent-child mapping to the map
            }
            
            buildMap(node.left, node);
            buildMap(node.right, node);
            // Recursively build the parent-child mapping for the left and right subtrees
        }
    }    
}
