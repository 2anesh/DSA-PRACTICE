class Solution{
	int water_flow(int [][] mat, int N, int M) {
		//Write your code here
		ArrayDeque<int[]> pacific_dq = new ArrayDeque<>();
        ArrayDeque<int[]> atlantic_dq = new ArrayDeque<>();
        
        for(int i=0;i<mat.length;i++) {
            pacific_dq.add(new int[]{i,0});
            atlantic_dq.add(new int[]{i,mat[i].length-1});
        }
        
        for(int i=0;i<mat[0].length;i++) {
            pacific_dq.add(new int[]{0,i});
            atlantic_dq.add(new int[]{mat.length-1,i});
        }
        
        
        byte[][] is_connected_pacific = bfs(pacific_dq,mat);
        byte[][] is_connected_atlantic = bfs(atlantic_dq,mat);
        
        List<List<Integer>> ans = new ArrayList<>();
        
        for(int i=0;i<mat.length;i++) {
            for(int j=0;j<mat[i].length;j++) {
                if(is_connected_pacific[i][j]==1 && is_connected_atlantic[i][j]==1) {
                    ans.add(Arrays.asList(i,j));
                }
            }
        }
        return ans.size();
	}
	
	public byte[][] bfs(ArrayDeque<int[]> dq,int[][] heights) {
        byte[][] visit = new byte[heights.length][heights[0].length];
        while(dq.size()>0) {
            int[] index = dq.pop();
            int i = index[0];
            int j = index[1];
            visit[i][j]=1;
            
            // north or up
            if(isValid(visit,i-1,j) && heights[i-1][j]>=heights[i][j]) {
                dq.add(new int[]{i-1,j});
            }
            
            // south or down
            if(isValid(visit,i+1,j) && heights[i+1][j]>=heights[i][j]) {
                dq.add(new int[]{i+1,j});
            }
            
            // east or left
            if(isValid(visit,i,j-1) && heights[i][j-1]>=heights[i][j]) {
                dq.add(new int[]{i,j-1});
            }
            
            // west or right
            if(isValid(visit,i,j+1) && heights[i][j+1]>=heights[i][j]) {
                dq.add(new int[]{i,j+1});
            }
        }
        return visit;
    }
    
    public boolean isValid(byte[][] visit,int i,int j) {
        if(i<0 || j<0 || i>=visit.length || j>=visit[0].length || visit[i][j]==1) return false;
        return true;
    }
}
