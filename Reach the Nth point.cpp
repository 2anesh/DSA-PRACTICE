class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    int f1 = 1, f2 = 1;
		    int f = 0;
		    while(n){
		        f = f1 + f2;
		        f = f%1000000007;
		        f1 = f2;
		        f2 = f;
		        n--;
		    }
		    return f1;
		}
};
