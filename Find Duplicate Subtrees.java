class Solution {
    Map<String, Integer> map;
    List<TreeNode> res;
    
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        map = new HashMap<>();
        res = new ArrayList<>();
        dfs(root);
        return res;
    }
    
    private String dfs(TreeNode node) {
        if (node == null) {
            return "#";
        }
        String serial = node.val + "," + dfs(node.left) + "," + dfs(node.right);
        map.put(serial, map.getOrDefault(serial, 0) + 1);
        if (map.get(serial) == 2) {
            res.add(node);
        }
        return serial;
    }
}
