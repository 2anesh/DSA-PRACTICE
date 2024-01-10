class Solution {
    int longSubarrWthSumDivByK(int[] arr, int n, int k) {
        
        HashMap<Integer, Integer> mp = new HashMap<>();
        int ans = 0, sum = 0;
        mp.put(0, -1);
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            int r = sum % k;
            if (r < 0) r += k; 
            if (!mp.containsKey(r)) mp.put(r, i);
            else ans = Math.max(ans, i - mp.get(r));
        }
        return ans;
    }
}
