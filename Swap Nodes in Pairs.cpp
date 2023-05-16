class Solution {
public:
ListNode* swapPairs(ListNode* head) {
ListNode* curr=head;
ListNode* prev=NULL;
ListNode* fwd=NULL;
int cnt=0;
while(curr!=NULL && cnt<2){
fwd=curr->next;
curr->next=prev;
prev=curr;
curr=fwd;
cnt++;
}
if(curr!=NULL){
head->next=swapPairs(fwd);
}
head=prev;
return head;
}
};
