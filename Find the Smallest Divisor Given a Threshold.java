class Solution 
{
    
    public int smallestDivisor(int[] nums, int threshold) 
    {
        int     m = 0;
        int     l = 1;
        int     r = max( nums );

        while( l <= r )
        {
            if( sum( nums, threshold, m = (l + r) / 2 ) )
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        
        return l;
    }
    
    // --- Utility method to find max value in an array ---
    
    private static int max( int[] nums )
    {
        int     max = 0;
        
        for( int n : nums )
        {
            max = Math.max( max, n );
        }
        
        return max;
    }

    // --- Utility method to perform sum and compare against threshold (i.e. t) ---
    
    private static boolean sum( int[] nums, int t, int d )
    {
        int     sum = 0;
        
        for( int n : nums )
        {
            sum += (n - 1) / d + 1;
        }
        
        return sum > t;
    }
}
