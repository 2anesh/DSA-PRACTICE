class Solution {
public:
    int search(vector<int>& nums, int target) {
     
      int s = 0;
      int e = nums.size() - 1;
       int mid = s+(e-s)/2;
       while(s<= e){

       if (nums[mid] == target){
           return mid;
       }
        if (nums[mid]> target){
            e= mid -1;

        }
        else{
            s = mid +1 ;

        }

        mid = s+ (e-s)/2;







        
    }return -1;
    
       }
};
