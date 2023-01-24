class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    int temp[n];
	    for(int i=0;i<n;i++){
	        temp[i]=arr[i];
	    }
	    sort(temp,temp+n);
        
	    for(int i =0;i<n;i++){
        int st=0;
	    int end =n-1;
	    int mid= st+(end-st)/2;
            
	        while(st<=end){
	            
	            if(temp[mid]==arr[i]){
	                arr[i]=mid;
	               
	                break;
	            }
	            else if(temp[mid]<arr[i]){
	                st=mid+1;
	            }
	            else if(temp[mid]>arr[i]){
	                end=mid-1;
	            }
	            mid= st+(end-st)/2;
	        }
	    }
	}

};
