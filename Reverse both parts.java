class Solution {
    public static Node reverse(Node head, int k) {
        // Separate into two LinkedList
        
        Node head1=null,head2=null;
        head1=head;
        Node t=head1;
        while(k!=1){
            t=t.next;
            k--;
        }
        head2=t.next;
        t.next=null;
        
        head1=reverse(head1);
        head2=reverse(head2);
        
        //Add two LinkedList
        Node head3=head1;
        Node prev=null;
        while(head3!=null){
            prev=head3;
            head3=head3.next;
        }
        prev.next=head2;
        
        return head1;
    }
    static Node reverse(Node node)
    {
        Node prev = null;
        Node current = node;
        Node next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        node = prev;
        return node;
    }
    
}
