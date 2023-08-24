class Solution{
  public:
    /*You are required to complete below function */
     string check(string &s1,int x,string &ans,int minus)
    {
        string sol;
        int i = ans.size()-1-minus;
        int z = ans.size()-1;
        while(i<z)
        {
            sol+=ans[z];
            z--;
        }
        int carry = 0;
        for(int j=s1.size()-1;j>=0;j--)
        {
            int cal = (s1[j]-'0')*x;
            cal+=carry;
            if(i>=0)
            {
                cal+=(ans[i]-'0');
                i--;
            }
            sol+=((cal%10)+'0');
            carry = cal/10;
        }
        if(carry>0)
        {
            sol+=(carry+'0');
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
    string multiplyStrings(string s1, string s2) {
        int count = 0;
        if(s1[0]=='-')
        {
            count++;
            s1 = s1.erase(0,1);
        }
        if(s2[0]=='-')
        {
            count++;
            s2 = s2.erase(0,1);
        }
        string ans;
        int x = 0;
        for(int i=s2.size()-1;i>=0;i--)
        {
            ans = check(s1,s2[i]-'0',ans,x);
            x++;
            // cout<<ans<<endl;
        }
        while(ans.size()>1 and ans[0]=='0')
        {
            ans = ans.erase(0,1);
        }
        if(ans.size()>1 || (ans.size()==1 and ans[0]!='0'))
        {
            if(count%2)
            {
                ans = '-'+ans;
            }
        }
        return ans;
    }

};
