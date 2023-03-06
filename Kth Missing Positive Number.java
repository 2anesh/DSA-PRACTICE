class Solution {
    public static int findKthPositive(int[] arr, int k) {
        for(int i=0;i<arr.length;i++)
        {
            int x=arr[i]-(i+1);
            if(x>=k)
                return i+k;
        }
        return arr.length+k;
    }   
  
}
