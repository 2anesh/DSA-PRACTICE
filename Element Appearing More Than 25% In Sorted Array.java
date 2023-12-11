class Solution {
    public int findSpecialInteger(int[] arr) {
        int size = arr.length;
        int qtr = size / 4;
        int cnt = 1;
        int x = arr[0];
        for (int i=1;i<arr.length;i++) {
            if (x == arr[i]) cnt++;
            else cnt = 1;

            if (cnt > qtr) return arr[i];

            x = arr[i];
        }
        
        return x;
    }
}
