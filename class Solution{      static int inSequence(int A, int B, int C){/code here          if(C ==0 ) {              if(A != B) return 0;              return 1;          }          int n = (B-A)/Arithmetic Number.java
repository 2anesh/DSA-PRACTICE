class Solution{

    static int inSequence(int A, int B, int C){

        // code here

        if(C ==0 ) {

            if(A != B) return 0;

            return 1;

        }

        int n = (B-A)/C; 

        if(n < 0) return 0;

        int rem= (B-A)%C; 

        if(rem == 0 ) return 1;

        else return 0;

    }

}

