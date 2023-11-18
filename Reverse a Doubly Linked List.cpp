class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if(head->next==NULL)return head;
        Node* curr=head;
        Node* temp=NULL;
        while(curr){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
            
        }
        return temp->prev;
    }
};
