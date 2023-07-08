class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr,arr+n);
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int t=arr[i]+arr[j]+arr[k];
                if(t==0){
                    return 1;
                }
                else if(t>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return 0;
    }
};
