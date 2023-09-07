class Solution {
    // fuction used to reverse a linked list from left  to right
    public ListNode reverseBetween(ListNode head, int left, int right) {
        // first move the current pointer to the node from
        // where we have to reverse the linked list
        ListNode curr = head, prev = null;
        // pre pints to the node before the left node.
        int i;
        for(i=1;i<left;i++)
        {
            prev = curr;
            curr= curr.next;
        }
        // this pointer stores the pointer to the head of 
        // the reversed list
        ListNode rtail = curr;
        // so this one pointer stor th pointer to the tail of 
        // the reversed linked list
        ListNode rhead = null;
        
        // now reverse the linked list from right to left.
        while(i <= right)
        {
            ListNode next = curr.next;
            curr.next = rhead;
            rhead = curr;
            curr = next;
            i++;
        }
        // if prev is not null it means some of the right node where we will connect th tail if the reverse LL.
        if(prev != null)
          prev.next = rhead;
        else
        head = rhead;

        rtail.next = curr;
        // at the end return the new head.
        return head;
    }
}
