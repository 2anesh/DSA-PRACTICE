class Solution {

    public long[] optimalArray(int n,int a[])

    {

        long[] minNumOfOperations = new long[n];

        

        // First Element will need NO Operations

        // so, pushing 0

        minNumOfOperations[0] = 0;

        

        for(int i = 1; i < n; i++) {

            // Index of Median Element

            int index = i/2;

            // All Elements should reach the Median Elment -> Subtracting Median

            // Adding the Min. No. of Operations of Previous Elements

            minNumOfOperations[i] = a[i]-a[index] + minNumOfOperations[i-1];

        }

        

        return minNumOfOperations;

    }

}
