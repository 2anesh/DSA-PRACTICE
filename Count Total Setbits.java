class Solution {
   public static long countBits(long n) {

		long count = 0, idx = 0;

		for (int i = 31; i >= 0; i--)
			count += ((n & (1 << i)) > 0) ? ((i * (1 << i) / 2 + (1 << i) * idx++) + 1) : 0;

		return count;
	}
}
