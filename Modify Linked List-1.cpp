class Solution{
    public:
    Node* reverse(Node* head){
        if(!head || !head->next){
            return head;
        }
        Node* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        // Break the linked List from middle in O(n) time Using fast and slow pointers
        if(!head || head->next  == NULL)
            return head;
        Node* fast = head->next->next,*slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast != NULL)
            slow = slow->next;
        Node* head2 = reverse(slow->next);
        slow->next =  NULL;
        Node* t1 = head, *t2 = head2;
        while(t1 && t2){
            t1->data = t2->data - t1->data;
            t2->data = t2->data - t1->data;
            t1 = t1->next, t2= t2->next;
        }
        head2 = reverse(head2);
        slow->next = head2;
        return head;
    }
};
