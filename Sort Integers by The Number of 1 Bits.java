class Solution {
    public int[] sortByBits(int[] arr) {
        int n = arr.length;
        int[] sortedResult = new int[n];
        for(int i = 0 ; i < n ; i++){
            sortedResult[i] = countSetBit(arr[i]) * 10001 + arr[i];
        }
        Arrays.sort(sortedResult);
        for(int i = 0 ; i < n ; i++){
            sortedResult[i] %= 10001;
        }

        return sortedResult;
    }
    public int countSetBit(int n){
        int count = 0;
        while(n != 0){
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
}
