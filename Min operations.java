class Solution {
    public static int solve(int a, int b) {
        //If both the numbers are equal then no need to perform any operation
        if(a == b){
            return 0;
        }
        int diffBitsA  = 0, diffBitsB = 0,minOperations = 0;
        //Check for all the 32 bits
        for(int i = 0;i<32;i++){
            int bitA = (a>>i) & 1;
            int bitB = (b>>i) & 1;
            //Keep track of count of bits  which are 1 in a and 0 in b
            if(bitA == 1 && bitB == 0){
                diffBitsA++;
            }
            //Keep track of bits which are 1 in b and 0 in a
            if(bitA == 0 && bitB == 1){
                diffBitsB++;
            }
        }
        //If diffBitsA > 0 then we can toggle all the 1 bits to 0 in one operation
        minOperations += diffBitsA > 0 ? 1: 0;
        //If diffBitsB > 0 then we can toggle all the 1 bits to 0 in one operation
        minOperations += diffBitsB > 0 ? 1: 0;
        return minOperations;
        
    }
}
        
