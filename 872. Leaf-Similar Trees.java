class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> list1 = new ArrayList();
        List<Integer> list2 = new ArrayList();
        leafNode(root1,list1);
        leafNode(root2,list2);
        return list1.equals(list2);
    }
    public void leafNode(TreeNode root,List list){
      if(root==null)return;
      if(root.left==null&&root.right==null){
          list.add(root.val);
      }
       leafNode(root.left,list);
       leafNode(root.right,list);
    }
 }
