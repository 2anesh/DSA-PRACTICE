class Solution {
public int diagonalSum(int[][] mat) {
int n=mat.length;
int s = 0; //starting index for each row element
int e = mat.length-1; //last elemetn for each row element
int sum=0;

    for(int[] arr: mat)
    {
        sum+=arr[s]+arr[e];
        s++;
        e--;
    }
    if(n*n%2==0){   //if matrix has no common element(n*n is even)
        return sum;
    }
    else{
        sum = sum - mat[n/2][n/2]; //if matrix has common element
        return sum;
    }
        
    
}
}
