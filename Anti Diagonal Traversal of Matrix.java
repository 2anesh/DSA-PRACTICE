class Solution
{
    public int[] antiDiagonalPattern(int[][] matrix)
    {
        // Code here
        int n=matrix.length;
        int m=matrix[0].length;
        ArrayList<Integer> ans=new ArrayList<>();
        int row=0;
        int col=0;
        while(row<n && col<m){
            int i=row;
            int j=col;
            while(i<n && j>=0){
                ans.add(matrix[i][j]);
                i++;
                j--;
            }
            if(col<m-1){
                col++;
            }else{
                row++;
            }
        }
        int[] ret = new int[ans.size()];
        for (int i=0; i < ret.length; i++)
        {
            ret[i] = ans.get(i).intValue();
        }
        return ret;

    }
}
