class Solution {
    public void Rearrange(int arr[], int n)
    {
        int temp[] = new int[n];
        // store -ves
        int k = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0) {
                temp[k++] = arr[i];
            }
        }
        // store +ves
        for(int i = 0; i < n; i++) {
            if(arr[i] >= 0) {
                temp[k++] = arr[i];
            }
        }
        // store elements back in original array
        for(int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
}
