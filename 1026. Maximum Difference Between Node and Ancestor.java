class Solution {
int maxdiff;
public int maxAncestorDiff(TreeNode root) {
if(root == null)return 0;
    maxdiff = Integer.MIN_VALUE;
    dfs(root, root.val, root.val);
    return maxdiff;
}
private void dfs(TreeNode root, int min , int max)
{
    if(root == null)return;
    maxdiff = Math.max( maxdiff,  Math.max(Math.abs( root.val - min ), Math.abs(max - root.val)));    
    dfs(root.left,Math.min(min,root.val),Math.max(max,root.val));//check for left part    
    dfs(root.right,Math.min(min,root.val),Math.max(max,root.val));//check for right part
                       
}
}
