static long solve(int X,int Y, String S)
	{    
	    // code here
        long ans;
        if(X<Y) {
            ans = f(Y,X,S,'r','p');
        } else {
            ans = f(X,Y,S,'p','r');
        }
        return ans;
	}
	
	public static long f(long x,long y,String s,char c1,char c2) {
	    Stack<Character> st = new Stack<>();
	    long ans=0;
	    for(int i=0;i<s.length();i++) {
	        char c = s.charAt(i);
	        if(c==c2) {
	            if(st.size()>0 && st.peek()==c1) {
	                st.pop();
	                ans+=x;
	            } else {
	                st.push(c);
	            }
	        } else {
	            st.push(c);
	        }
	    }
	    
	    Stack<Character> st1 = new Stack<>();
	    while(st.size()>0) {
	        if(st.peek()==c2) {
	            if(st1.size()>0 && st1.peek()==c1) {
	                ans+=y;
	                st1.pop();
	                st.pop();
	            } else {
	                st1.push(st.pop());
	            }
	        } else {
	            st1.push(st.pop());
	        }
	    }
	    return ans;
	}
C++ Code :-

long long solve(int X,int Y,string S){
      //code here
      long ans;
      if(X<Y) {
          ans = f(Y,X,S,'r','p');
      } else {
          ans = f(X,Y,S,'p','r');
      }
      return ans;
    }
    
    long long f(int x,int y,string s,char c1,char c2) {
        stack<char> st;
        long long ans=0;
        for(int i=0;i<s.length();i++) {
            char c = s[i];
            if(c==c2) {
                if(st.size()>0 && st.top()==c1) {
                    st.pop();
                    ans+=x;
                } else {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }
        
        stack<char> st1;
        while(st.size()>0) {
            if(st.top()==c2) {
                if(st1.size()>0 && st1.top()==c1) {
                    ans+=y;
                    st1.pop();
                    st.pop();
                } else {
                    st1.push(st.top());
                    st.pop();
                }
            } else {
                st1.push(st.top());
                st.pop();
            }
        }
        return ans;
    }
