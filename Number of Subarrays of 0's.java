class Solution{
	long no_of_subarrays(int n, int [] a) {
		
		long count = 0;
		long ans = 0;
		for(int i=0;i<n;i++){
		    if(a[i] == 0){
		        count++;
		        if(i==n-1){
		            ans += (count*(count+1))/2;
		        }
		    }else{
		        ans += (count*(count+1))/2;
		        count = 0;
		    }		  
		}
		return ans;
		
	}
}
