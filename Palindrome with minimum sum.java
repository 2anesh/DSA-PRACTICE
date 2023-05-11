class Solution {
    public static int minimumSum(String s) {
        // code here
        char d[] = s.toCharArray();
         int n=s.length();
        int i=0,j=n-1;
        int count=0;
        char prev='$';
        while(i<j)
        {
            if(d[i]!='?' && d[j]!='?' && d[i]!=d[j]) return -1;
            else if(d[i]=='?' && d[j]!='?') 
            {
                // s[i]=s[j];
                if(prev!='$') count+=Math.abs(d[j]-prev);
                prev=d[j];
            }
            else if(d[i]!='?' && d[j]=='?') 
            {
                // s[j]=s[i];
                if(prev!='$') count+=Math.abs(d[i]-prev);
                prev=d[i];    
            }
            else if(d[i]==d[j] && d[i]!='?')
            {
                if(prev!='$') count+=Math.abs(d[i]-prev);
                prev=d[i];  
            }
            i++;j--;
        }
        return 2*count;
    }
}
