class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
//if the value of s==0 return -1 because in question we have given that the array contain digit >1 so no chance of 0 ever finding pair
        if(s==0) return {-1};
        int i = 0;
        int j = i+1;
        long long sum = arr[i];
        while(i<=j&&j<n)
        {
            if(sum>s)
            {
                while(i<n && sum>s)
                {
                    sum = sum-arr[i];
                    i++;
                }
            }
            else if(sum==s) break;
            
            else{sum +=arr[j];
            j++;}
            
        }
// a last if condition outside the loop because after the addition of the last digit the sum may have become greater than s
        if(sum>s)
        {
        while( i<n && sum>s)
            {
                sum = sum-arr[i];
                i++;
            }
        }
//checking if sum is not equal to s return -1
        if(sum!=s ) return {-1};
        return {i+1,j};
    }
};
