class Solution {
    ArrayList<Integer> list;
    int i;
    
    public void inorder(Node node){
        if(node==null){
            return;
        }
        
        //L
        inorder(node.left);
        
        //D
        list.add(node.data);
        
        //R
        inorder(node.right);
    }
    
    public void solve(Node node){
        if(node==null){
            return;
        }
        
        //L
        solve(node.left);
        
        //D
        int ele=list.get(i);
        i++;
        node.data=ele;
        
        //R
        solve(node.right);
    }
    
    public Node correctBST(Node root) {
        list=new ArrayList<>();
        i=0;
        
        //inorder
        inorder(root);
        
        //sort
        Collections.sort(list);
        
        //solve
        solve(root);
        
        return root;
    }
}
