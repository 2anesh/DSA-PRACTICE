class Solution {
public:
    // Function to count subarrays with elements in the range [L, R].
    long countSubarrays(int a[], int n, int L, int R) {
        // Initialize variables to keep track of the window and count.
        long count = 0;
        int i = 0;
        int j = 0;
        int window = 0;

        // Iterate through the array using two pointers.
        while (j < n) {
            // If the current element is within the range [L, R], update the window size.
            if (a[j] >= L && a[j] <= R) {
                window = max(window, j - i + 1);
            } 
            // If the current element is greater than R, reset the window and move the left pointer.
            else if (a[j] > R) {
                window = 0;
                i = j + 1;
            }
            // If the current element is less than L, update the window size if the previous window was non-zero.
            else {
                window = max(0, window);
            }

            // Update the count with the current window size.
            count += window;

            // Move the right pointer to the next element.
            j++;
        }

        // Return the total count of subarrays with elements in the range [L, R].
        return count;
    }
};
