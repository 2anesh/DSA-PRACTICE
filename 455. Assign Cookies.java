class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int count = 0;
        int k = 0;
        for(int l = 0; k<g.length && l<s.length; l++){
            if(g [k] <= s[l]){
                k++;
            }
        }
        return k;
    }
}
