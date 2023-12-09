class Solution {

     List<Integer> ans = new ArrayList<>();
    public List<Integer> inorderTraversal(TreeNode root) {
        traverse(root);
        return ans;
    }
    void traverse(TreeNode root){
        if(root==null){
            return;
        }
        traverse(root.left);
        ans.add(root.val);
        traverse(root.right);
    }

}
