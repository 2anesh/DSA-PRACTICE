class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	  int count(int arr[], int n, int x) {
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(auto i:m){
            if(i.first==x){
                return i.second;
            }
        }
        return 0;
    }
};
