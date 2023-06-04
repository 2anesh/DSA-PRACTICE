class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string str = "";
            stack<char>st;
            stack<string>sn; int j=0, k=0;
            for(int i=0; i<s.length(); i++)
            {
                if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                {
                    st.push(s[i]);
                    if(!str.empty())
                    sn.push(str);
                    str="";
                    j++;
                    k=0;
                    
                }
                else
                  {  str += s[i];
                    k++;
                    j=0;}
                
            }
            if(!str.empty())
            sn.push(str);
            str = "";
            while(!sn.empty() || !st.empty())
            {
                if(k>j){
                if(!sn.empty())
                {
                    str += sn.top();
                    sn.pop();
                }
                if(!st.empty())
                {
                    str += st.top();
                    st.pop();
                }}
                
                if(k<j){
                if(!st.empty())
                {
                    str += st.top();
                    st.pop();
                }
                if(!sn.empty())
                {
                    str += sn.top();
                    sn.pop();
                }}
                
                
            }
            
            return str;
        }
};
