class Solution {
    bool isAnagram(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        
        array<int, 26> arr{};
        for(int i = 0; i < s1.size();i++) {
            arr[s1[i] - 'a']++;
            arr[s2[i] - 'a']--;
        }        
        for(int i : arr) {
            if(i!=0) return false;
        }
        return true;
    }
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<Node*> ans;
        Node* front = head;
        Node* prev = nullptr;
        if(!head) return ans;
        
        while(head){
            string tempStr ;
            for(int i = 0; i < s.size(); i++){
                if(head) {
                    tempStr.push_back(head->data);
                    prev = head;
                    head = head->next;
                }
            }
            
            if(isAnagram(tempStr,s)) {
                ans.push_back(front);
                prev->next = nullptr;
            } else {
                head = front->next;
            }
            front = head;
        }
    }
};
