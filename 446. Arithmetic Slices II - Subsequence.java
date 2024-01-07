class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        	if (A.length < 3) {
			return 0;
		}
		int ans = 0;
		HashMap<Integer, Integer>[] map = new HashMap[A.length];
		for (int i = 0; i < A.length; i++) {
			map[i] = new HashMap<>(i);
			for (int j = 0; j < i; j++) {
				long diff = (long) A[i] - A[j];
				if (diff <= Integer.MIN_VALUE || diff > Integer.MAX_VALUE)
					continue;
				int d = (int) diff;
				int c1 = map[i].getOrDefault(d, 0);
				int c2 = map[j].getOrDefault(d, 0);
				ans += c2;
				map[i].put(d, c1 + c2 + 1);
			}
		}

		return ans;
    }
}
