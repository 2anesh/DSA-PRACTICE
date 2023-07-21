class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
              node* curr = head;
        int length=0;
        while(curr!=NULL)
        {
            length++;
            curr = curr->next;
        }
        
        node* dummyHead = new node(0);
    dummyHead->next = head;
    
    node* pre = dummyHead;
    node* cur;
    node* nex;
    
    while(length > 1) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
            if(nex==NULL)
            break;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
    }
};
