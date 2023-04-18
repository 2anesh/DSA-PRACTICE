class Solution {
    static int ans = Integer.MAX_VALUE; //track of the minimum size of the subtree
    
    public static int minSubtreeSumBST(int target, Node root) {
        ans = Integer.MAX_VALUE; // reset the inctance variable
        find(target, root); // find the minimum size of the subtree
        return ans == Integer.MAX_VALUE ? -1 : ans; // if ans is still Integer.MAX_VALUE, it means no subtree was found
    }
    
    public static void find(int target, Node root) {
        if (root == null) return; // base case
        
        int sum = sum(root); // calculate the sum of the current subtree
        if (sum == target && isBST(root)) { // if the sum is equal to target and the current subtree is a BST
            ans = Math.min(ans, size(root)); // update the global variable with the minimum size
        }
        
        find(target, root.left); // recursively find in left subtree
        find(target, root.right); // recursively find in right subtree
    }
    
    private static int sum(Node root) { // helper method to calculate the sum of a subtree
        if (root == null) return 0;
        return root.data + sum(root.left) + sum(root.right);
    }
    
    private static int size(Node root) { // helper method to calculate the size of a subtree
        if (root == null) return 0;
        return 1 + size(root.left) + size(root.right);
    }
    
    private static boolean isBST(Node root) { // helper method to check if a subtree is a BST
        return isBSTUtil(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    private static boolean isBSTUtil(Node node, int min, int max) { // utility method for checking if a subtree is a BST
        if (node == null) return true;
        
        if (node.data < min || node.data > max) return false;
        
        return isBSTUtil(node.left, min, node.data - 1)
            && isBSTUtil(node.right, node.data + 1, max);
    }
}
