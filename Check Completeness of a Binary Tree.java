class Solution {
    public boolean isCompleteTree(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        boolean seenNull = false;
        
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            
            if (node == null) {
                seenNull = true;
                continue;
            }
            
            if (seenNull) {
                return false;
            }
            
            queue.add(node.left);
            queue.add(node.right);
        }
        
        return true;
    }
}
