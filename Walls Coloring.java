class Solution{
	int minCost(int [][] a, int n){
	    for(int i=1; i< n; i++){
	        a[i][0]+=Math.min(a[i-1][1], a[i-1][2]);
	        a[i][1]+=Math.min(a[i-1][0], a[i-1][2]);
	        a[i][2]+=Math.min(a[i-1][1], a[i-1][0]);
	    }
	    return Math.min(a[n-1][0], Math.min(a[n-1][1],a[n-1][2]));
    }
}
