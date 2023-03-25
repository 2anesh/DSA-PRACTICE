class Solution
{
    public static String removeBrackets(String Exp){
        //code here
        char[]s=Exp.toCharArray();
        int n=Exp.length();
        
        int ans[]=new int[n+1];
        Arrays.fill(ans,1);
        int lasta[]=new int[n+1];
        int nxta[]=new int[n+1];


        int l=-1;
        for(int i=0;i<n;i++){
            lasta[i]=l;
            if(s[i]=='*'||s[i]=='+'||s[i]=='-'||s[i]=='/')
                    l=s[i];
        }
        l=-1;
        for(int i=n-1;i>=0;i--){
            nxta[i]=l;
            if(s[i]=='*'||s[i]=='+'||s[i]=='-'||s[i]=='/')
                    l=s[i];
        }


        Stack<Integer> st=new Stack<>();
        int sign[]=new int[256];
        int mp[]=new int[256];
        Arrays.fill(sign,-1);
        char[] operand={'*','+','-','/'};

        for(int p=0;p<n;p++)
        {
            for(char x:operand){
                mp[x]=0;
                if(x==s[p])
                    sign[x]=p;
            }
            if(s[p]=='(')
                st.push(p);

            else if(s[p]==')'){
                int i=st.pop();
                int j=p;

                int nxt=nxta[j];
                int last=lasta[i];
                
                for(char x:operand){
                    if(sign[x]>=i){
                        mp[x]=1;
                    }
                }
                int ok=0;
                
                if(i>0 && j+1<n && s[i-1]=='(' && s[j+1]==')')
                    ok=1;
                if(mp['+']==0 && mp['*']==0 && mp['-']==0 && mp['/']==0)
                    ok=1;
               

                if(last==-1&&nxt==-1)
                    ok=1;
                if(last=='/'){

                }
                else if(last=='-'&&(mp['+']==1||mp['-']==1)){
                    
                }
                else if(mp['-']==0&&mp['+']==0){
                    ok=1;
                }
                else{
                    if((last==-1||last=='+'||last=='-')&&(nxt==-1||nxt=='+'||nxt=='-'))
                        ok=1;
                }
                if(ok==1){
                    ans[i]=0;
                    ans[j]=0;
                }
                               
            }
        }
        StringBuffer res=new StringBuffer();
        for(int i=0;i<n;i++){
            if(ans[i]>0){
                res.append(s[i]);
            }
        }
        return res.toString();
    }
}

