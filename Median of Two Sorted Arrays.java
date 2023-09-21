class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length = nums1.length + nums2.length;
        float median = 0;
        int[] mergedArray = new int[length];
        int index = 0;
        for(int i : nums1){
            mergedArray[index] = i;
            index++;
        }
        for(int i : nums2){
            mergedArray[index] = i;
            index++;
        }
        Arrays.sort(mergedArray);
        int mergedArrayLength = mergedArray.length;
        if(mergedArrayLength%2==0){
            int closestIndexValue = mergedArrayLength/2;
            median = mergedArray[closestIndexValue] + mergedArray[closestIndexValue-1]; 
            median /= 2; 
        }else{
            int closestIndexValue = mergedArrayLength/2;
            median = mergedArray[closestIndexValue];
        }
        return median;
    }
}
