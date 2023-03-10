class Solution {
    private ListNode head;
    private Random rand;

    public Solution(ListNode head) {
        this.head = head;
        this.rand = new Random();
    }
    
    public int getRandom() {
        ListNode current = head;
        int count = 1;
        int result = 0;
        
        while (current != null) {
            if (rand.nextInt(count) == 0) {
                result = current.val;
            }
            count++;
            current = current.next;
        }
        
        return result;
    }
}
