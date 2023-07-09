class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        int a[1000001]={0};
        for(int i=0; i<n; i++){
            if(arr[i]<=0){
                continue;
            }else{
                a[arr[i]]++;
            }
        }
        for(int i=1; i<1000001; i++){
            if(a[i]<1){
                return i;
            }
        }
    } 
};

 
