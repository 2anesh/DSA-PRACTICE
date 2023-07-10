class Solution {
    public int minDepth(TreeNode root) {
        if(root==null)
            return 0;
        int min = Integer.MAX_VALUE;
        if(root.left==null&&root.right==null)
            return 1;
        if(root.left!=null)
            min=1+minDepth(root.left);
        if(root.right!=null)
            min=Math.min(min,1+minDepth(root.right));
    return min;
        
    }
    
}
