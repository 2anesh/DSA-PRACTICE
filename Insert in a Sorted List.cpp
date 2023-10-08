class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node* temp = head;
        Node* dummy = new Node(data);
        Node* prev = NULL;
        
        while(temp) {
            //prev = temp;
            if(temp -> data >= data) {
                dummy -> next = temp;
                if(prev == NULL) {
                    return dummy;
                }
                else {
                    prev -> next = dummy;
                    return head;
                }
            }
            else {
                prev = temp;
                temp = temp -> next;
            }
        }
        
        prev -> next = dummy;
        return head;
    }
};
