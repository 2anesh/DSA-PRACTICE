class Solution {
public:

ListNode* mergeKLists(vector<ListNode*>& lists) {
   vector<int> v;
    for(int i=0;i<lists.size();i++){
        while(lists[i]){
            v.push_back(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    if(v.size()==0) return NULL;
    sort(v.begin(),v.end());
    ListNode *temp = new ListNode(v[0]);
    ListNode *head = temp;
    for(int i=1;i<v.size();i++){
        ListNode* newnode = new ListNode(v[i]);
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}
};
