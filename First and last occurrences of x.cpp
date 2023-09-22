class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int low=0,high=n-1;
        int in=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                in=mid;
                high=mid-1;
            }
            if(arr[mid]>x) high=mid-1;
            if(arr[mid]<x) low=mid+1;
          
        }
        low=0,high=n-1;
        int in1=-1;
          while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                in1=mid;
                low=mid+1;
            }
            if(arr[mid]>x) high=mid-1;
            if(arr[mid]<x) low=mid+1;
           
        }
     return {in,in1};
    }
};
