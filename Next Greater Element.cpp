class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans(n, -1);
        stack<long long> st;
        st.push(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && arr[i]>=st.top()){
                st.pop();
            }   
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};
