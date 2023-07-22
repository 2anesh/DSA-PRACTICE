class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     Node *temp = head;
     Node *pre = temp;
     unordered_map<int,int> count;
     while(temp){
         count[temp->data]++;
         if(count[temp->data] > 1){
             pre->next=temp->next;
             temp = temp->next;
         }
         else{
            pre = temp;
            temp = temp->next;
         }
     }
     return head;
    }
};
