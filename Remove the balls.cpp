class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        
        stack<pair<int,int>> st;
        
        for (int i=0; i<N; i++) {
            pair<int, int> pii = {color[i], radius[i]};
            if (!st.empty() and st.top() == pii) st.pop();
            else st.push(pii);
        }
        
        return st.size();
    }
};
