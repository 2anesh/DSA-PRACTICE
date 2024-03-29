class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
      Node* temp=new Node(-1);
      Node* sum=temp;
      while(head1 && head2)
      {
          if(head1->data==head2->data)
          {
              sum->next=new Node(head2->data);
              sum=sum->next;
              head1=head1->next;
              head2=head2->next;
          }else if(head1->data>head2->data){
              head2=head2->next;
          }else{
              head1=head1->next;
          }
      }
      return temp->next; 
    }
};
