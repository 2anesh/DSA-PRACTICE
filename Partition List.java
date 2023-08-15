class Solution {
    public ListNode partition(ListNode head, int x) {
      
      ListNode headBeforeResult=new ListNode();
      ListNode node = head;
      ListNode resultBefore=headBeforeResult;
      ListNode headAfterResult=new ListNode();
      ListNode resultAfter = headAfterResult;
      
      while(node!=null){
        if(node.val<x){
          resultBefore.next=new ListNode(node.val);
          resultBefore=resultBefore.next;
        }else{
          resultAfter.next=new ListNode(node.val);
          resultAfter=resultAfter.next;
        }
        node=node.next;
      }
      resultBefore.next=headAfterResult.next;
      
      return headBeforeResult.next;
    }
}
