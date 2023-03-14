class Solution {
    private int sum;
    public int sumNumbers(TreeNode root) {
        sum = 0;
        traverseBT(root, new StringBuilder());
        return sum;
    }

    private void traverseBT(TreeNode node, StringBuilder sb) {
        if (node == null) return;

        sb.append(node.val);

        if (node.left == null && node.right == null) {
            sum += Integer.parseInt(sb.toString());
        }
        traverseBT(node.left, sb);
        traverseBT(node.right, sb);
        sb.deleteCharAt(sb.length() - 1);
    }
}
