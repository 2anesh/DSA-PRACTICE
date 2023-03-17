long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long ans=0;
    long long count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            ans+=((count)*(count+1))/2;
            count=0;
        }
        else
            count++;
    }
    ans+=((count)*(count+1))/2;
    return ans;
}

