class Solution{
public:
    int getNthFromLast(struct Node *head, int n)
{
    if(head==NULL)
    return -1;
    struct Node *temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    if(n>cnt)
    return -1;
    int pos=cnt-n;
    temp=head;
    while(pos)
    {
        temp=temp->next;
        pos--;
    }
    return temp->data;
}
};
