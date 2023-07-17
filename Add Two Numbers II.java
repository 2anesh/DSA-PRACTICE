class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        Stack<Integer> stk1=new Stack<>();
        Stack<Integer> stk2=new Stack<>();

        while(l1 != null){
            stk1.push(l1.val);
            l1=l1.next;
        }

        while(l2 != null){
            stk2.push(l2.val);
            l2=l2.next;
        }

        ListNode ans=null;
        int carry=0;

        while(!stk1.empty() || !stk2.empty() || carry !=0){
            int dgt1= !stk1.empty() ? stk1.pop() : 0;
            int dgt2= !stk2.empty() ? stk2.pop() : 0;
            
            int sum= dgt1+dgt2+carry;
            int dgt=sum % 10;
            carry= sum/10;

            ListNode nnode = new ListNode(dgt);
            nnode.next=ans;
            ans= nnode;
        }
       return ans;
    }
}
