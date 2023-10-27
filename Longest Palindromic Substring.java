class Solution {
    public String longestPalindrome(String s) {
        String [][]dp=new String[s.length()][s.length()];
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++)
                dp[i][j]="";
        }
        return lp(s,0,s.length()-1,dp);
    }
    public static String lp(String s,int n1,int n2,String [][]dp){
        if(n1==n2)
            return dp[n1][n2]=s.charAt(n1)+"";
        if(dp[n1][n2]!="")
            return dp[n1][n2];
        int flag=0;
        for(int i=n1,j=n2;i<=n2;i++,j--){
            if(! (s.charAt(i)==s.charAt(j))){
                flag=1;
                break;
            }
        }
        if(flag==0)
            return dp[n1][n2]=s.substring(n1,n2+1);
        String s1=lp(s,n1+1,n2,dp);
        String s2=lp(s,n1,n2-1,dp);
        if(s1.length()>s2.length())
            return dp[n1][n2]=s1;
        return dp[n1][n2]=s2;
    }
}
