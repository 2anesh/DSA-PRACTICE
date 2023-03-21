class Solution {
    public static int minimumTime(int N, int cur, int[] pos, int[] time) {
        int min = Integer.MAX_VALUE;
        for(int i=0;i<pos.length;i++){
            int temp = Math.abs(cur-pos[i]) * time[i];
            min = (temp<min) ? temp : min;
        }
        return min;
    }
}
        
