class Solution {
    public int minimumOneBitOperations(int n) {
       int ans=0;
       int one=0;
       for(int i=31;i>=0;i--){
         if(((n>>i)&1)!=0){
           if(one==0){
             ans+=1<<i;
             one=1;
           }
           else{
             one=0;
           }          
         }
         else{
           if(one!=0){
             ans+=1<<i;
           }
         }
       } 
       return ans;
    }
}
