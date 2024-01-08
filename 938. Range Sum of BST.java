class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;
        return (
           ( root.val >= low && root.val<= high ? root.val:0)+
           (low<root.val ? rangeSumBST(root.left ,low,high):0)+
           (high>root.val ? rangeSumBST(root.right ,low,high):0)
        );
    }
}
