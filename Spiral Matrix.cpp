class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int m = matrix.size(); //No of rows;
       int n = matrix[0].size(); // nO of columns;

       vector<int> spiral;
       if (m == 0)
        return spiral;

        //Defining some variables to iterate over the matrix
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = m;
        int colEnd = n;

        int k; //Counter 

        while(rowStart < rowEnd && colStart < colEnd)
        {
            for(k = colStart ; k < colEnd ; k++)
            {
                spiral.push_back(matrix[rowStart][k]);
            }
            rowStart++;

            for( k = rowStart; k < rowEnd ; k++)
            {
                spiral.push_back(matrix[k][colEnd-1]);
            }
            colEnd--;

            if(rowStart < rowEnd)
            {
                for(k = colEnd-1; k >= colStart; k--)
                    spiral.push_back(matrix[rowEnd-1][k]);
                rowEnd--;
            }

            if(colStart < colEnd)
            {
                for(k = rowEnd - 1; k >= rowStart; k--)
                    spiral.push_back(matrix[k][colStart]);
                colStart++;
            }
        }

        return spiral;
    }
};
