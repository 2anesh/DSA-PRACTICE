class Solution{   
public:
    long long solve(int X,int Y,string S){
      long long p=0,r=0;
      
        stack<char> st,st2;
        st.push(S[0]);
        
        
        if(X>Y){
                for(int i=1;i<S.size();i++)
                {
                    if( !st.empty() && ( st.top()=='p' && S[i]=='r' ))
                    {
                        st.pop();
                        p++;
                    }
                    else st.push(S[i]);
                }
                
                
                st2.push(st.top());
                
                st.pop();
              
                
                while(!st.empty())
                {
                    if(!st2.empty() && (st2.top()=='p' && st.top()=='r'))
                    {
                        st.pop();
                        r++;
                        st2.pop();
                    }
                else
                    {
                        st2.push(st.top());
                        st.pop();
                    }
                }
        }
        else
        {
                for(int i=1;i<S.size();i++)
                {
                    if(!st.empty() && (st.top()=='r' && S[i]=='p'))
                    {
                        st.pop();
                        r++;
                    }
                    else
                    {
                        st.push(S[i]);
                    }   
                }
                st2.push(st.top());
                
                st.pop();
             
                while(!st.empty())
                {
                    if(!st2.empty() && (st.top()=='p' && st2.top()=='r'))
                    {
                        st.pop();
                        p++;
                        st2.pop();
                    }
                else
                    {
                        st2.push(st.top());
                        st.pop();
                    }
                }
        } 
        
        return p*X+r*Y; 
        
    }
};

