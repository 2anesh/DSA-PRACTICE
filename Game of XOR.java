class Solution {
    static int gameOfXor(int N , int[] A) {
        if(N%2==0)return 0;
        int ans=A[0];
        for(int i=1;i<N;i++){
            if(i%2==0){
                ans=ans^A[i];
            }
        }
        return ans;
    }
};
