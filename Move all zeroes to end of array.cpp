class Solution{
public:
    void pushZerosToEnd(int arr[], int n) {
        // code here
        int i=0;
        if(i==n)
            return;
        while(i<n){
            if(arr[i]==0)
            for(int j=i+1;j<n;j++){
                if(arr[j] != 0){
                    swap(arr[i],arr[j]);
                    break;
                }
            }
            i++;
        }
    }
};
