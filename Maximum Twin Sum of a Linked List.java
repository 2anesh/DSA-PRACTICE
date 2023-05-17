class Solution {
    public int pairSum(ListNode head) {
        // Having only two values as inputs.
        if (head.next.next == null) {
            return head.val + head.next.val;
        }
        
        // Using this to get to the middle of the linkedlist.
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Reverse the linkedlist starting from the node that slow is currently pointing to.
        ListNode prev = null;
        while (slow != null) {
            ListNode nextNode = slow.next;
            slow.next = prev;
            prev = slow;
            slow = nextNode;
        }
        
        // Reset fast to point to head and creat a max variable
        fast = head;
        int max = Integer.MIN_VALUE;
        
        // Since prev is now pointing to the begining of the reversed second half,
        // while prev is not null, perform the sum of fast.val and pre.val and compare
        // with max and replace if needed.
        while (prev != null) {
            int newMax = fast.val + prev.val;
            if (newMax > max) {
                max = newMax;
            }
            
            fast = fast.next;
            prev = prev.next;
        }
        
        // Return result.
        return max;
    }
}
