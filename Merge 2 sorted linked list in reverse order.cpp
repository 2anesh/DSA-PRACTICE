class Solution
{
    public:
    
    Node* Reverse(Node* node)
    {
        if(node==NULL)
        {
            return node;
        }
        if(node->next==NULL)
        {
            return node;
        }
        Node* cur=node;
        Node* prev=NULL;
        Node* nex=node->next;
        while(nex!=NULL)
        {
            cur->next=prev;
            prev=cur;
            cur=nex;
            nex=nex->next;
        }
        cur->next=prev;
        return cur;
    }
     Node* Merge(Node* n1, Node* n2)
    {
        Node* one=n1;
        Node* two=n2;
        Node* prev;
        Node* ans;
        if(n1->data > n2->data)
        {
            ans=n1;
            prev=n1;
            n1=n1->next;
        }
        else
        {
            Node* temp=n1;
            n1=n2;
            n2=temp;
            ans=n1;
            prev=n1;
            n1=n1->next;
        }
        while(n1!=NULL && n2!=NULL)
        {
            if(n1->data>=n2->data)
            {
                prev=n1;
                n1=n1->next;
            }
            else
            {
                prev->next=n2;
                prev=n2;
                Node* temp=n1;
                n1=n2->next;
                n2=temp;
            }
        }
        if(n2!=NULL)
        {
           prev->next =n2;
        }
        return ans;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node* n1=Reverse(node1);
        Node* n2=Reverse(node2);
        if(n1!=NULL && n2!=NULL)
        {Node* node=Merge(n1,n2);
        return node;}
        else
        {
            if(n1==NULL)
            return n2;
            
            if(n2==NULL)
            return n1;
        }
    }  
};
