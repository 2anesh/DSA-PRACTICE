class Solution {
    public static int minimumInteger(int N, int[] A) {
         
         long sum=0; 
         int min=Integer.MAX_VALUE;
         
         for(int i=0;i<A.length;i++)
         {
             sum=sum+A[i];
         }
         
         for(int i=0;i<A.length;i++)
         {
             if(sum<=(long)A.length*A[i])
             {
                 if(A[i]<min)
                   min=A[i];
             } 
         }
         
         return min;
         
    }
}
