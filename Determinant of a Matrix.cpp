class Solution
{   
    public:
    int determinantOfMatrix(vector<vector<int> > matrix, int p)
    {
        if (p == 1)
            return matrix[0][0];
        int det = 0;
        for (int j = 0; j < p; j++)
        {
            int sign = (j % 2 == 0) ? 1 : -1;
            int cofactor = sign * matrix[0][j] * determinantOfMinor(matrix, p, 0, j);
            det += cofactor;
        }
        return det;
    }
    int determinantOfMinor(vector<vector<int>>&matrix, int p, int row, int col)
    {
        vector<vector<int>> minorMatrix(p - 1, vector<int>(p - 1, 0));
        int minorRow = 0, minorCol = 0;
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < p; k++)
            {
                if (j != row && k != col)
                {
                    minorMatrix[minorRow][minorCol++] = matrix[j][k];
                    if (minorCol == p - 1)
                    {
                        minorCol = 0;
                        minorRow++;
                    }
                }
            }
        }
        return determinantOfMatrix(minorMatrix, p - 1);
    }
};
