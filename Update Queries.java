class Solution{
	int [] updateQuery(int N, int Q, int [][]U){
        //Write your code here
        int[] result = new int[N];
        
        for(int[] queries: U)
        {
            int l = queries[0];
            int r = queries[1];
            int x = queries[2];
            
            for(int i=l-1; i<r; i++)
            {
                result[i] = result[i] | x;
            }
        }
        return result;
    }
}
