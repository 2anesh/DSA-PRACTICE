class Solution {
      public double champagneTower(int poured, int query_row, int query_glass) {
        double[][] glasses = new double[query_row + 1][query_row + 1];
        glasses[0][0] = poured;
        for (int row = 0; row < query_row; row++) 
        {  for (int glass = 0; glass <= row; glass++) 
            { if (glasses[row][glass] >= 1) //checking if the glass is full
                {
                    glasses[row + 1][glass] += (glasses[row][glass] - 1) / 2.0;
                    glasses[row + 1][glass + 1] += (glasses[row][glass] - 1) / 2.0;
                    //glasses[row][glass] = 1;
                }
            }
        }
        return Math.min(1, glasses[query_row][query_glass]);
    }
}
