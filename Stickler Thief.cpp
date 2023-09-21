class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solvemem(int arr[],int n,int i,vector<int>&dp){
        if(i>n) return 0;
        if(i==n) return arr[n];
        if(dp[i]!=-1) return dp[i];
        
        int include=solvemem(arr,n,i+2,dp)+arr[i];
        int exclude=solvemem(arr,n,i+1,dp)+0;
        return dp[i]=max(include,exclude);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n,-1);
        return solvemem(arr,n-1,0,dp);
    }
};
