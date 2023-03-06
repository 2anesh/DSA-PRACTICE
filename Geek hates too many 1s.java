class Solution {
    public static int noConseBits(int n) {
        // code here
        int c = 0;
        for(int i=31;i>=0;i--){
            if((n & (1<<i))!=0)
            c++;
            else c = 0;
            
            if(c==3){
                n = n & ~(1<<i);
                c = 0;
            }
        }
        return n;
        
    }
}    
