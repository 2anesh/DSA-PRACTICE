class Solution {
    public int numSpecial(int[][] mat) {
        
        int count = 0;
        int r = mat.length;
        int c = mat[0].length;
        
        int rsum = 0;
        int csum = 0;

        int col = -1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j] == 1){
                    col = j;
                }
                rsum+=mat[i][j];
            }

            if(rsum ==1){
                for(int rows = 0;rows<mat.length;rows++){
                    csum+=mat[rows][col];
                }
            }

            if(csum==1){
                count++;
            }

            csum=0;
            rsum=0;
        }
        return count;
    }
}
