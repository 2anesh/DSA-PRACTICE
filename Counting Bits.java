class Solution {
    public int[] countBits(int n) {
        
        int[] arr = new int[n+1];
        
        for(int j =  0; j<=n; j++){
            int count = 0;
            int i = j;
            while( i != 0){
                i = i & (i-1);
                count++;
            }
            arr[j] = count;
        }
        return arr;
    }
}
