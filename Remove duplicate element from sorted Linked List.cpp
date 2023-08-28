Node *removeDuplicates(Node *head)
{
    Node* begin = head;
    while(head->next!=NULL)
    {
         if(head->data == head->next->data)
         {
             
               Node* temp = head->next;
               head->next = head->next->next;
               delete temp;
               
         }
         else 
        {
              head = head->next;
        }
    }
    return begin;
}
