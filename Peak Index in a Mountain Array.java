class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        // define the start and end index of the array
        int start = 0;
        int end = arr.length - 1;

        // Keep searching until start index is less than end index
        while (start < end){
            // calculate the middle index
            int mid = start + (end - start)/2;

            // check if the middle element is greater than the next element
            if(arr[mid] > arr[mid+1]){
                // if true, set the end index to the middle index
                end = mid;
            }else{
                // if false, set the start index to the middle index + 1
                start = mid + 1;
            }
        }
        // return the end index, which is the peak
        return end;
    }
}  
