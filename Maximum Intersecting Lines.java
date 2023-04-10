class Solution {
    public int maxIntersections(int[][] lines, int N) {
        // Code here
        //Arrays.sort(lines,Comparator.comparingInt(o -> o[0]));
        int count = 0 , maxCount = 0;
        int a[] = new int[N];
        int b[] = new int[N];
        for(int i=0;i<N;i++){
            a[i] = lines[i][0];
            b[i] = lines[i][1];
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int i = 0 , j = 0;
        while(i<N){
            if(a[i] <= b[j]){
                count++;
                maxCount = Math.max(count,maxCount);
                i++;
            }
            else{
                count--;
                j++;
            }
        }
        return maxCount;
    }
}
