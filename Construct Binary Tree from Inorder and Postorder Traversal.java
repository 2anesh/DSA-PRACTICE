class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        // create a map to store the index of each element in the inorder array
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
        // recursively construct the binary tree
        return buildTreeHelper(inorder, postorder, map, 0, inorder.length - 1, 0, postorder.length - 1);
    }
    
    private TreeNode buildTreeHelper(int[] inorder, int[] postorder, Map<Integer, Integer> map, 
                                     int inStart, int inEnd, int postStart, int postEnd) {
        // base case
        if (inStart > inEnd || postStart > postEnd) {
            return null;
        }
        // create the root node of the binary tree
        int rootVal = postorder[postEnd];
        TreeNode root = new TreeNode(rootVal);
        // find the index of the root node in the inorder array
        int rootIndex = map.get(rootVal);
        // recursively construct the left and right subtrees
        root.left = buildTreeHelper(inorder, postorder, map, inStart, rootIndex - 1, postStart, 
                                    postStart + rootIndex - inStart - 1);
        root.right = buildTreeHelper(inorder, postorder, map, rootIndex + 1, inEnd, postStart + rootIndex - inStart, 
                                     postEnd - 1);
        return root;
    }
}
