class Solution {
    int count = 0;
    int maxCount = 0;
    TreeNode prev;
    List<Integer> list= new ArrayList();
    public int[] findMode(TreeNode root) {
        prev=root;
        inorder(root);
        int n =  list.size();
        int[] result = new int[n];
        for(int i = 0; i<n; i++)
            result[i]=list.get(i);
        return result;
    }
    private void inorder(TreeNode node){
        if (node == null)
            return;
        inorder(node.left);
        if (node.val == prev.val)
            count++;
        else 
            count=1;
        if (count > maxCount){
            list.clear();
            maxCount = count;
            list.add(node.val);
        }else if (count == maxCount)
            list.add(node.val);
        prev= node;
        inorder(node.right);
    }
}
