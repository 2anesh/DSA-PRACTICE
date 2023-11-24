class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int k=piles.length/3;
        int c=0;
        for(int i=k;i<piles.length;i=i+2){
          c=c+piles[i];
        }
        return c;
    }
}
