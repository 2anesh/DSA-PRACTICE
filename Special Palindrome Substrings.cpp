class Solution{
    public:
    int specialPalindrome(string s1, string s2){
        string s = s1;
        int mini = 1000000;
        int m = s1.size();
        int n = s2.size();
        for(int i=0;i<m-n+1;++i){
            s = s1;
            int count = 0;
            for(int j=i,k=0;j<i+n;++j,++k){
               if(s[j]!=s2[k]){
                   ++count;
                   s[j]=s2[k];
               } 
            }
            int ele = solve(s,i,i+n-1);
            if(ele == -1){
                continue;
            }
            count = count + ele;
            mini = min(count,mini);
        }
        if(mini>=1000000){
            return -1;
        }
        return mini;
    }

    int solve(string s,int l,int h){
        int n = s.size();
        int i=0,j=n-1;
        int count = 0;
        while(i<j){
            if((i>=l && i<=h)&&(j<=h && j>=l)){
                if(s[i]!=s[j]){
                    return -1;
                }
            }
            else if(s[i]!=s[j]){
                ++count;
            }
            ++i;
            --j;
        }
      return count;  
    }
};
