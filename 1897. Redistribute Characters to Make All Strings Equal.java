class Solution {
    public boolean makeEqual(String[] words) {
        int p = words.length;
        int[] count = new int[26];
        for (String word : words) {
            for (char ch : word.toCharArray()) {
                count[ch - 'a']++;
            }
        }
        for (int k = 0; k < 26; k++) {
            if (count[k] % p != 0) {
                return false;
            }
        }
        return true;
    }
}
