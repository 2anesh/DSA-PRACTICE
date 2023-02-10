class Solution {
    public int maxInstance(String s) {
        if(s.length() < 7) return 0;
        int arr[] = new int[26];
        for(char ch : s.toCharArray())
        arr[ch-'a']++;
        int singleOccuring = Math.min(arr['b'-'a'], Math.min(arr[0], arr['n'-'a']));
        int doubleOccuring = Math.min(arr['l'-'a'], arr['o'-'a']);
        doubleOccuring /= 2;
        return Math.min(doubleOccuring , singleOccuring);
    }
}
