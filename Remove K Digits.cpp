class Solution {
  public:
   string removeKdigits(string S, int k) {
        stack<char>st;
        for(int j=0; j<S.size(); j++){
            while(!st.empty() and st.top()>S[j] and k){
                st.pop();
                k--;
            }
            st.push(S[j]);
        }
        if(st.empty())
            return "0";
        while(k--)
            st.pop();
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int j=0;
        while(res[j]=='0')
            j++;
        if(j==res.size())
            return "0";
        return res.substr(j);
   }
    };
