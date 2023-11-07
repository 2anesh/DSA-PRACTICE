class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
         double[] inti=new double[dist.length];
         for(int i=0;i<dist.length;i++){
                inti[i]=(double)dist[i]/speed[i];
         }
         Arrays.sort(inti);
         int monster=0;
         for(int i=0;i<inti.length;i++){
             if((inti[i]-i)>0){
                 monster++;
             }
             else{
                 return monster;
             }
         }
         return monster;
    }
}
