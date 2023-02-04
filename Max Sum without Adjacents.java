class Solution {
    int findMaxSum(int arr[], int n) {
        // code here
        if(n == 1){ return arr[0]; }
        if(n == 2){ return Math.max(arr[0],arr[1]); }
        
        arr[2] += arr[0];
        for(int i=3; i<n; i++){
            arr[i] += Math.max(arr[i-2],arr[i-3]);
        }
        
        return Math.max(arr[n-1],arr[n-2]);
        
    }
}
