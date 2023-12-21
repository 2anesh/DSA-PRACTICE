class Solution {
    // Method to calculate the maximum width of vertical area
    public int maxWidthOfVerticalArea(int[][] points) {
        // Sorting the points based on the x-coordinate (Time complexity: O(n log n))
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));

        int max_width = 0;

        // Iterating through the sorted points to find the maximum width
        for (int i = 1; i < points.length; i++) {
            // Calculating the width between consecutive x-coordinates
            int width = points[i][0] - points[i - 1][0];
            // Updating the maximum width if the current width is greater
            max_width = Math.max(max_width, width);
        }

        return max_width; // Returning the maximum width of vertical area
    }
}
