class Solution {
public:
    int intersectPoint(Node* head1, Node* head2) {
        if(!head1 or !head2) return -1;
        
        Node* curr = head1;
        while (curr->next) curr = curr->next;
        curr->next = head2;
        
        Node *slow = head1, *fast = head1;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                fast = head1;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow->data;
            }
        }
        return -1;
    }
};
