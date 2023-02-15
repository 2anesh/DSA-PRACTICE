class Solution {
private:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        
        string ans="";
        
        int carry=0;
        while(i>=0||j>=0||carry!=0)
        {
            int sum=0;
            if(i>=0)
            {
                sum+=num1[i]-'0';
                i--;
            }
            if(j>=0)
            {
                sum+=num2[j]-'0';
                j--;
            }
            sum+=carry;
            carry=sum/10;
            ans+=to_string(sum%10);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
    string number="";
    for(int i=0;i<num.size();i++)
    {
        number+=to_string(num[i]);
    }
        string str=to_string(k);
        string ans=addStrings(number,str);
        vector<int>v;
        int i=0;
   while(i<ans.length())
   {
       v.emplace_back(ans[i]-'0');
       i++;
   }

        return v;
    }
};
