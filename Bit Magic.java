class Solution {
    public static int bitMagic(int n, int[] arr) {
        // code here
        int op=0;
        for(int i=0; i<n/2; i++){
            if(arr[i]!= arr[n-1-i]){
                op++;
            }
        }
        return (op+1)/2;
    }
}
        
