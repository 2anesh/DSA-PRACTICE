public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int A) {
			int countSetBits=0;
    	int B=0;
    	if(A<0) {
    		B=A;
    		A=~A;
    	}
    	while(A>0)
    	{
    		System.out.println(A);
    		if((A&1)==1) {
    			countSetBits++;
    		}
        	A=A>>1;
    	}
    	if(B<0) {
    		countSetBits=32-countSetBits;
    	}
        return countSetBits;
    }
}
