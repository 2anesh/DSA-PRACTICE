class Solution {
    public int findLongestChain(int[][] pair) {
        Arrays.sort(pair, Comparator.comparingDouble(o -> o[1]));
        int chainLength=1;
        int lastNum=pair[0][1];
        for(int i=1;i<pair.length;i++){
            if(pair[i][0]>lastNum){
                chainLength++;
                lastNum=pair[i][1];
            }
        }
        System.out.println(chainLength);
        return chainLength;
    }
}
