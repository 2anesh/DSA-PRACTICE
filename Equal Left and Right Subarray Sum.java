class Solution{
	int equalSum(int [] A, int N) {
		//Write your code here
		int after = 0, before = 0;
		
		for(int n : A) {
		    after += n;
		}
		
		for(int i = 0; i< N; i++) {
		    if(i > 0){
		        before += A[i-1];
		    }
		    after -= A[i];
		    if(after == before) {
		        return i+1;  // according to question array is one indexed
		    }
		}
		return -1;
	}
}
