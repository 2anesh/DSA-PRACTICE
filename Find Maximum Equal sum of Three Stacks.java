class Solution {
    public static int maxEqualSum(int N1,int N2,int N3, int[] S1, int[] S2, int[] S3) {
        // code here
        int sum1 = 0,sum2 = 0,sum3 = 0;
        for(int i:S1)sum1+=i;
        for(int i:S2)sum2+=i;
        for(int i:S3)sum3+=i;
        int idx1 = 0,idx2 = 0,idx3 = 0;
        int mini = Math.min(sum1,Math.min(sum2,sum3));
        while(idx1< S1.length && idx2 <S2.length && idx3<S3.length){
            while(idx1<S1.length && sum1>mini){
                sum1-=S1[idx1++];
            }
            while(idx2<S2.length && sum2>mini){
                sum2-=S2[idx2++];
            }
            while(idx3<S3.length && sum3>mini){
                sum3-=S3[idx3++];
            }
            if(sum1 == sum2 && sum2 == sum3)return sum1;
            mini = Math.min(sum1 ,Math.min(sum2,sum3));
        }
        return 0;
    }
}
