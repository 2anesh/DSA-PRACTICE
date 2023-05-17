class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        int midlength=0;
        ListNode *fast=head, *slow=head;
        while (fast){
            fast=fast->next->next;
            slow=slow->next;
            midlength++;
        }
        int mid2=midlength;
        ListNode *go=head;
        while(midlength--){
            st.push(go->val);
            go=go->next;
        }
        int res,ans=INT_MIN;
        while(mid2--){
            res= st.top()+ slow->val;
            ans=max(res,ans);
            slow=slow->next;
            st.pop();
        }
        return ans;
    }
};
