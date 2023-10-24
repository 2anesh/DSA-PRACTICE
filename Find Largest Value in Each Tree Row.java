class Solution {
    List<Integer> largeVal = new ArrayList<Integer>();

    public List<Integer> largestValues(TreeNode root) {
        levelTraverse(root);
        return largeVal;
    }

    public void levelTraverse(TreeNode root){
        if (root == null){
            return;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while(!q.isEmpty()){
            int sz = q.size();
            int maxVal = Integer.MIN_VALUE;
            for (int i=0;i<sz;i++){
                TreeNode cursor = q.poll();
                if (cursor.left!=null){
                    q.offer(cursor.left);
                }
                if (cursor.right!=null){
                    q.offer(cursor.right);
                }
                maxVal = Math.max(maxVal,cursor.val);
            }
            largeVal.add(maxVal);
        }
    }
}
