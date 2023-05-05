class Solution
{   
    static int count = 0;
    static void find(HashSet<Integer> set , Node root , int k)
    {
        if(root == null)
        {
            return ;
        }
        HashSet<Integer> left_set = new HashSet<>();
        HashSet<Integer> right_set = new HashSet<>();
        
        find(left_set , root.left , k);
        find(right_set , root.right , k);
          
        left_set.addAll(right_set);
        left_set.add(root.data);
      
        if(left_set.size() <= k)
        {
            count++;
        }
        set.addAll(left_set);
        
    }
    public static int goodSubtrees(Node root,int k)
    {
        count = 0;
        HashSet<Integer> set = new HashSet<>();
        find(set , root , k);
        return count;
    }
}
