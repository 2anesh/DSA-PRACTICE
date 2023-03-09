class TreeHeightDiameter{
	int height;
	int diameter;
	TreeHeightDiameter(){
		
	}
	TreeHeightDiameter(int height,int diameter){
		this.height=height;
		this.diameter=diameter;
	}
}
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        TreeHeightDiameter ans= diameterTree(root);
		return ans.diameter;   
    }
    public static TreeHeightDiameter diameterTree(TreeNode root) {
		if(root==null) {
			return new TreeHeightDiameter(0, 0);
		}
		TreeHeightDiameter leftTree=diameterTree(root.left);
		TreeHeightDiameter rightTree=diameterTree(root.right);
		int height=1+Math.max(leftTree.height,rightTree.height);
		int diameter=Math.max(leftTree.height+rightTree.height, Math.max(leftTree.diameter, rightTree.diameter));
		return new TreeHeightDiameter(height,diameter);
	}
}
