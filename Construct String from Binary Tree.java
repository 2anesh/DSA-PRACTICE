class Solution {
    public String tree2str(TreeNode root) {
        StringBuilder s = new StringBuilder();
        creator(root, s);
        return s.toString();
    }
    
    public void creator(TreeNode root, StringBuilder s) {
        if (root == null) {
            return;
        }
        
        s.append(root.val);
        
        if (root.left != null || root.right != null) {
            s.append('(');
            creator(root.left, s);
            s.append(')');
            
            if (root.right != null) {
                s.append('(');
                creator(root.right, s);
                s.append(')');
            }
        }
    }
}
