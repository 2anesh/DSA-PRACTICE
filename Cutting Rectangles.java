class Solution{

    static long commanfactor(long A, long B ){

        if(B == 0) return A;

        return commanfactor(B,A%B);

    }

    static List<Long> minimumSquares(long L, long B)

    {

        // code here

        long dim = commanfactor(L,B); //dimension

        long nos = (L*B) / (dim*dim); // No.of squre

        List<Long> ls = new ArrayList<>();

        ls.add(nos);

        ls.add(dim);

        return ls;

    }

}
