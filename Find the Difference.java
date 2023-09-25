class Solution {
    public char findTheDifference(String s, String t) {
   
        int a[] = new int[26];
		int b[] = new int[26];
	for (char c : s.toCharArray()) {
			a[c - 'a']++;
		}

		for (char c : t.toCharArray()) {
			b[c - 'a']++;

            if (b[c - 'a'] > a[c-'a'])
				return c;
        }
    return 0;

    }
}
