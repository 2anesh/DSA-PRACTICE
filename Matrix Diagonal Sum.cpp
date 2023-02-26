class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0; // for storing the ans (sum)
        int n=mat.size(); //for rows
        int m=mat[0].size();// for column
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j || (i+j)==mat.size()-1)
                    sum+=mat[i][j]; 
            }
        }
        return sum;
    }
};
