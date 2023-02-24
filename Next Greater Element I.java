class Solution {
public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] arr = new int[nums2.length];
        Stack<Integer> st = new Stack<>();
        st.push(nums2[nums2.length - 1]);
        arr[nums2.length - 1] = -1;
        for (int i = nums2.length - 1; i >= 0; i--) {
            while (!st.isEmpty() && nums2[i] >= st.peek()) {
                st.pop();
            }
            if (st.isEmpty()) {
                arr[i] = -1;
            } else {
                arr[i] = st.peek();
            }
            st.push(nums2[i]);
        }
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i <nums2.length; i++) {
            hm.put(nums2[i], arr[i]);
        }
        System.out.println(hm);
        // int[] query = { 5, 7, 9 };
         int[] ans = new int[nums1.length];

        for (int i = 0; i < nums1.length; i++) {
            ans[i] = hm.get(nums1[i]);
        }
    return ans;
    }
}
