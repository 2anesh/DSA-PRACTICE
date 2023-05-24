class Solution {
    public long maxScore(int[] num1, int[] num2, int k) {
        int n=num1.length;
        int[][] pair=new int[n][2];
        for(int i=0;i<n;i++){
            pair[i][0]=num1[i];
            pair[i][1]=num2[i];
        }
        Arrays.sort(pair,(a,b)->b[1]-a[1]);
        PriorityQueue<Integer> q=new PriorityQueue<>();
        long sum=0L;
        long ans=Long.MIN_VALUE;
        for(int i=0;i<n;i++){
            q.add(pair[i][0]);
            sum+=pair[i][0];
            if(q.size()>k){
                sum-=q.poll();
            }
            if(q.size()==k){
                ans=Math.max(ans,sum*pair[i][1]);
            }
        }
        return ans;
    }
}
