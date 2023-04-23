class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        int left =0, right=n-1;
        while(left<right){
            if(arr[left]>=arr[right]) arr[left]=arr[left]%arr[right];
            else if(arr[right]>=arr[left]) arr[right]=arr[right]%arr[left];
            
            if(arr[left]==0) left++;
            else if(arr[right]==0) right--;
        }
        return arr[left];
    }
};
