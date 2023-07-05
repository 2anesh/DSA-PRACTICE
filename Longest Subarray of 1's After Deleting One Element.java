class Solution {
    public int longestSubarray(int[] A) {
    int i = 0, j, count = 1;
    for (j = 0; j < A.length; j++) {
        if (A[j] == 0) count--;
        if (count < 0 && A[i++] == 0) count++;  // if arr[i]==0 then i++ karo ..aur count++ bhi karo 
    }
    return j - i - 1;
}
}
