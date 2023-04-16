class Solution {
    public static long solve(int N, int[] A, int[] B) {
        // code here
        long sumA =0;
        long sumB =0;
        long difference =0;
        int count =0;
        for (int i=0; i<N;i++){
            sumA+=A[i];
            sumB+=B[i];
        }
        if (sumA != sumB){
            return -1;
        }
        Arrays.sort(A);
        Arrays.sort(B);
        int firstA=0;
        int firstB=0;
        while(firstA<N && firstB<N){
            if (A[firstA]==B[firstB]){
                A[firstA] = 0;
                B[firstB]=0;
                firstA++;
                firstB++;
            }else if(A[firstA]>B[firstB]){
                firstB++;
            }else{
                 firstA++;
            }
        }
        Arrays.sort(A);
        Arrays.sort(B);
        for (int i=0; i<N;i++){
            if (A[i]!=0)count++;
            difference+=Math.abs(A[i]-B[i]);
        }
        if (difference == 0){
            return 0;
        }else if (difference%2!=0){
            return -1;
        }
        else{
            long even=0;   
            int j=0;
            int k=0;
            while(j<N && k<N){
                if (A[j]%2==0&&B[k]%2==0){
                    even += Math.abs(A[j]-B[k]);
                    j++;
                    k++;
                }else if(A[j]%2!=0){
                    j++;
                }else{
                    k++;
                }
            }
            long odd=0;   
            int p=0;
            int q=0;
            while(p<N && q<N){
                if (A[p]%2!=0&&B[q]%2!=0){
                    even += Math.abs(A[p]-B[q]);
                    p++;
                    q++;
                }else if(A[p]%2==0){
                    p++;
                }else{
                    q++;
                }
            }
            if (even==0&odd==0){
                return -1;
            }
            return Math.abs(even + odd)/4;
        
        }
    }
}
