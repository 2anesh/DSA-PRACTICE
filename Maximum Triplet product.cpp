class Solution {

  public:

    long long maxTripletProduct(long long arr[], int n)

    {

     sort(arr,arr+n);

     long long max1= max({1ll*arr[n-1]*arr[n-2]*arr[n-3],1ll*arr[n-1]*arr[0]*arr[1]});

     return max1;

    }

 

};
