class Solution {
public:
    int minOperations(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int answer1=0,answer2=0;
        string p,q;
        for(int i=0; i<s.size(); i++)
        {
            if(i&1)   
            {
                p += '0';
                q += '1';
            }
            else
            {
                p += '1';
                q += '0';
            }
        }
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=p[i])
                answer1++;
            else if(s[i]!=q[i])
                answer2++;
        }     
        return min(answer1, answer2);
    }
};
