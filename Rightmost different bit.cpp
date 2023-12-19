class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
         if(m==n) return -1;
         
         int rem1, rem2, counter=1;
         
         while(m || n){
             rem1= m%2;
             rem2=n%2;
             
             if(rem1==rem2){
                 counter++;
             }else{
                 return counter;
             }
             
             m=m/2;
             n=n/2;
             
         }
            
        
    }
};

