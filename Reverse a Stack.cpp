class Solution{
public:
    stack<int>s;
    void Reverse(stack<int> &st){
        if(st.empty()){
            st=s;
            return ;
        }
        s.push(st.top());
        st.pop();
        Reverse(st);
    }
};
