class Solution {
    /* Implementation of Monotonic Queue */
    class MonotonicQueue {
        LinkedList<Integer> q = new LinkedList<>();
        
        public void push(int n) {
            // Remove elements smaller than n
            while (!q.isEmpty() && q.getLast() < n) {
                q.pollLast();
            }
            // Add n to the end
            q.addLast(n);
        }

        public int max() {
            return q.getFirst();
        }

        public void pop(int n) {
            if (n == q.getFirst()) {
                q.pollFirst();
            }
        }
    }

    /* Implementation of the solution function */
    public int[] maxSlidingWindow(int[] nums, int k) {
        MonotonicQueue window = new MonotonicQueue();
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            if (i < k - 1) {
                // Fill the window with the first k - 1 elements
                window.push(nums[i]);
            } else {
                // Slide the window forward and add the new number
                window.push(nums[i]);
                // Record the current maximum in the window
                res.add(window.max());
                // Remove the outgoing number from the window
                window.pop(nums[i - k + 1]);
            }
        }
        // Convert to an int[] array before returning
        int[] arr = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            arr[i] = res.get(i);
        }
        return arr;
    }
}
