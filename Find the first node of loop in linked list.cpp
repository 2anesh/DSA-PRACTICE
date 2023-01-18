class Solution
{
public:
    int findFirstNode(Node* head)
    {
        Node* slow = head, *fast = head, *itr = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                while(itr != slow) {
                    itr = itr->next;
                    slow = slow->next;
                }
                
                return itr->data;
            }
        }
        
        return -1;
    }
};
