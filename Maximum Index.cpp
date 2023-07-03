class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
    // Create two auxiliary arrays of size n
    int *LMin = new int[(sizeof(int) * n)]; 
    int *RMax = new int[(sizeof(int) * n)]; 
  
    // Fill LMin array
    LMin[0] = arr[0]; 
    for (int i = 1; i < n; ++i) 
        LMin[i] = min(arr[i], LMin[i - 1]); 
  
    // Fill RMax array
    RMax[n - 1] = arr[n - 1]; 
    for (int j = n - 2; j >= 0; --j) 
        RMax[j] = max(arr[j], RMax[j + 1]); 
  
    // Initialize variables to find maximum value of j-i
    int i = 0, j = 0, maxDiff = -1; 
    
    // Find maximum value of j-i subjected to the constraint of arr[i] <= arr[j]

    while (j < n && i < n) { 
        if (LMin[i] <= RMax[j]) { 
            maxDiff = max(maxDiff, j - i); 
            j = j + 1; 
        } else
            i = i + 1; 
    } 
  
    // Return result
    return maxDiff; 
    }
};
