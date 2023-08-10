class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        int kp[n+1][m+1];
        for(int i =0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(i==0||j==0){
                    kp[i][j]=0;
                }
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    kp[i][j] = 1+kp[i-1][j-1];
                }
                else {
                    kp[i][j] = max(kp[i-1][j],kp[i][j-1]);
                }
            }
        }
        return kp[n][m];
    }
};
