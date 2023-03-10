class Solution {
public:
    vector<int> v;// This vector is used to store the value ehich is present in the linked list 
    Solution(ListNode* head) {
        while(head)
        {
            v.push_back(head->val);// push the each value into hte vector
            head=head->next;// this used for looping purpose
        }
    }
    
    int getRandom() {
        int n=v.size();//store the size of the vector in the 'n' variable
        int r=rand()%n;//rand() is used to genrate the random value by deafult 1 without seeding
        // eg: rand()->20 & n->3  ------> 20%3 --> 2
        return v[r];// we return the that 2 index value from the vector
    }
};
