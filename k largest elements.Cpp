class Solution{

public:

vector<int> kLargest(int arr[], int n, int k) {

    

    sort(arr,arr+n);

    

    vector<int>ans;

    

    while(k>0)

    {

       ans.push_back(arr[n-1]);

       n--;

       k--;

    }

    

    return ans;

}

 

};
