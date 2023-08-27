class Solution {
    boolean[][] dp;
    public boolean canCross(int[] stones) {
        
        if(stones[1]!=1) return false;
        
        int n = stones.length;
        dp = new boolean[n][n];
        return helper(stones,0,1);
    }
    
    boolean helper(int[] stones,int lastIndex,int currentIndex){
        if(currentIndex == stones.length - 1){
            return true;
        }
         
        if(dp[lastIndex][currentIndex]) return false;
        
        int lastJump = stones[currentIndex] - stones[lastIndex];
        
        int nextIndex = currentIndex + 1;
        
        while(nextIndex<stones.length && stones[nextIndex]<= stones[currentIndex] + lastJump + 1){
            int nextJump = stones[nextIndex] - stones[currentIndex];
            int jump = nextJump - lastJump;
            
            if(jump>=-1 && jump<=1){
                if(helper(stones,currentIndex,nextIndex)){
                    return true;
                }
            }
            nextIndex++;
        }
        
        dp[lastIndex][currentIndex] = true;
        
        return false;
    }
}  
