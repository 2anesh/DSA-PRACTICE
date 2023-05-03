class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        vector<int> arr;
        vector<vector<int>> ans;

        // num1 array elements which are not present in num2 array
        for(i=0 ; i<nums1.size() ; i++)
        {
            if(count(nums2.begin(), nums2.end(), nums1[i])==0)
            {
                if(count(arr.begin(), arr.end(), nums1[i])==0)
                {
                    arr.push_back(nums1[i]);
                }
            }
        }
        ans.push_back(arr);
        arr.clear();

        // num2 array elements which are not present in num1 array
        for(i=0 ; i<nums2.size() ; i++)
        {
            if(count(nums1.begin(), nums1.end(), nums2[i])==0)
            {
                if(count(arr.begin(), arr.end(), nums2[i])==0)
                {
                    arr.push_back(nums2[i]);
                }
            }
        }
        ans.push_back(arr);
        return ans;
    }
};
