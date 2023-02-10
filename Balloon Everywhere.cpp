class Solution{

public:

    int maxInstance(string s){

        vector<int> m(27,0) ;

        int i = 0 ;

        while(s[i]!='\0')

        {

            if(s[i]=='b' || s[i]=='a' || s[i]=='l' || s[i]=='o' || s[i]=='n')

            {

                m[s[i]-96]++ ;

            }

            i++ ;

        }

        int ans = m['b'-96]/1 ;

        ans = min(ans , m['a'-96]/1) ;

        ans = min(ans , m['l'-96]/2) ;

        ans = min(ans , m['o'-96]/2) ;

        ans = min(ans , m['n'-96]/1) ;

        return ans ;

    }

 

};
