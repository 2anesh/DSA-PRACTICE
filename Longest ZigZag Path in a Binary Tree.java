class Solution {

public class Pair{
    int forward=-1;
    int backward=-1;
    int max=0;
}
public Pair lon(TreeNode root){
    if(root==null) return new Pair();
    Pair left=lon(root.left);
    Pair right=lon(root.right);
    Pair ans=new Pair();
    ans.max=Math.max(Math.max(left.max,right.max),Math.max(left.backward,right.forward)+1);
    ans.forward=left.backward+1;
    ans.backward=right.forward+1;
    return ans;
}
public int longestZigZag(TreeNode root) {
   
    Pair p=lon(root);
    return p.max;
    
}
}
