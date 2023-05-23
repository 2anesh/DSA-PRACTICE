class Solution {
    public static int getMaximum(int N, int[] arr) {
        // code here
    long sum = 0;
    for(int i : arr) {
        sum += i;
    }
    for(int i = 0; i < N; i++) {
        if(sum % (N - i) == 0) {
            return N - i;
        }
    }
    return 0;
    }
}
