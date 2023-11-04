class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
        int low = 0, high = n-1, mid, flag;
        while(low<=high){
            mid = low + (high-low)/2;
            if(arr[mid]==0 && arr[mid+1]==1){
                return mid+1;
            }
            else if(arr[mid]==1){
                high = mid - 1;
                flag = 1;
            }
            else if(arr[mid]==0){
                low = mid + 1;
                flag = 0;
            }
        }
        if(flag==1) return 0;
        else return -1;
    }
};
