class Solution {
    public static ArrayList<Node> findAnagrams(Node head, String str) {
        // code here
        ArrayList<Node> ans1 = new ArrayList<>();
        String s="";
        Node p=head;
        
        while(head!=null){
            s+=head.data;
            if(s.length()==str.length()){
                if(isAnagram(s,str)){
                    addtoList(s,ans1);//method to add in ans
                    s="";
                }else{
                    s=s.substring(1);
                }
            }
            head=head.next;
        }
      
        return ans1;
        
    }
    static void addtoList(String e, ArrayList<Node> ans1){
        
         Node q= new Node('0');
         Node start=q;
        for(int i=0;i<e.length();i++){
            q.next=new Node(e.charAt(i));
            q=q.next;
        }
        
        ans1.add(start.next);
    }
    
    static boolean isAnagram(String s1 , String s2){
        char[] arr1 = s1.toCharArray();
        char[] arr2 = s2.toCharArray();
        Arrays.sort(arr1);
        Arrays.sort(arr2);      if(String.valueOf(arr1).equals(String.valueOf(arr2)))
        return true;
        return false;
    }
}
