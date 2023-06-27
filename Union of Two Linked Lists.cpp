class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int> st;
        Node *temp1=head1;
        Node *temp2=head2;
        while(temp1!=NULL){
            st.insert(temp1->data);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            st.insert(temp2->data);
            temp2=temp2->next;
        }
        Node *head=new Node(*st.begin());
        Node *temp=head;
        st.erase(st.begin());
        for(auto it:st){
            Node *node=new Node(it);
            temp->next=node;
            temp=node;
        }
        return head;
    }
};
