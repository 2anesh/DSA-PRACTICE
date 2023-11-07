class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        int sumUp = 0;
        int sumDown = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sumUp+=matrix[i][j];
                sumDown+=matrix[j][i];
            }
        }
        vector<int>result;
        result.push_back(sumUp);
        result.push_back(sumDown);
        return result;
    }
};
