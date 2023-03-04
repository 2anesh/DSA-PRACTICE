class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long res = 0;  //for storing the ans

        int start = 0;  //storing the index after we get the maxinum element
        int minStart = 0 , maxStart = 0;  //store the min and max Index of element 

        bool minF = false , maxF = false;   //check for minimum and maximun element 

        for(int i = 0; i<nums.size();i++)
        {
            int num = nums[i];

            if(num < minK || num > maxK)   //edge case
            {
                minF = false ;
                maxF = false ; 
                start = i+1;   //store the index after the max element
            }
            if(num == minK)   // if element is equal to min
            {
                minF = true;  //mark as minimum as true
                minStart = i;   //store its index
            }  
            if(num == maxK)      //if element is equal to max element
           {
                maxF = true;  //mark as true
                maxStart = i;   //store its index
            }

            //cout<<res<<" ";
            // cout<<maxStart << " "<<endl;
            // cout<<minStart << " ";

            if(minF && maxF)         //if we find both min and max index as true
            {
                //count the element between the min and max element
                res += (min(minStart,maxStart) - start + 1);
            }
        }
        return res;
        
    }
};
