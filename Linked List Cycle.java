public class Solution {
    public boolean hasCycle(ListNode head) {
        // Initialize two pointers, 'slow' and 'fast', both starting from the head of the linked list
        ListNode slow = head;
        ListNode fast = head;
        
        // Iterate through the linked list until either the 'fast' pointer reaches the end or becomes null
        while (fast != null && fast.next != null) {
            // Move the 'slow' pointer one step forward
            slow = slow.next;
            
            // Move the 'fast' pointer two steps forward
            fast = fast.next.next;
            
            // If the 'slow' and 'fast' pointers meet at the same node, a cycle exists
            if (slow == fast)
                return true;
        }
        
        // If the loop finishes without finding a cycle, return false
        return false;
    }
}
