class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0; //Pointer for characters in t
        int j = 0; //Pointer for characters in s
        while ((j < s.length()) && (i < t.length())) {
            if (t.charAt(i) == s.charAt(j)) {
                j++;
            }
            i++;
        }
        if (j == s.length()) return true; else return false;
    }
}
