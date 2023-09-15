class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        int []dis = new int[n];
        Arrays.fill(dis,Integer.MAX_VALUE);
        int ans=0;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                dis[j]=Math.min(dis[j],Math.abs(points[i][0]-points[j][0]) +Math.abs(points[i][1]-points[j][1]));
                if(dis[j]<dis[i+1]){
                    final int[] tempPoint = points[j];
                    points[j] = points[i + 1];
                    points[i + 1] = tempPoint;
                    final int tempDist = dis[j];
                    dis[j] = dis[i + 1];
                    dis[i + 1] = tempDist;
                }
            }
            ans+=dis[i+1];
        }
        return ans;
        
    }
}
