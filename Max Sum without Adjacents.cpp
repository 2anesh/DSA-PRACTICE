class Solution{

public: 

 // calculate the maximum sum with out adjacent

 int findMaxSum(int *arr, int n) {

    vector<int> dp(n,0);

    

    // as only arr[0] is present in an array of size 1

    dp[0] = arr[0];

    dp[1] = max(arr[0],arr[1]);
   for(int i = 2 ; i < n ; i++)

    {

        // case when we are not including the ith element for summation

        int nt = dp[i-1];

        // case when we are  including the ith element for summation so we can consider the answer upto till index i-2

        int t = arr[i]+dp[i-2];

        

        // at the current location saving the answer whichever is max by taknig the elemnt or not taknig the elemnt

        dp[i] = max(nt,t);

    }

     return dp[n-1];

 }

};
