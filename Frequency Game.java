class Solution {
    public static int LargButMinFreq(int arr[], int n) {
        HashMap<Integer,Integer>map = new HashMap();
        for(int i:arr) map.put(i,map.getOrDefault(i,0)+1);
        int freq = Integer.MAX_VALUE,max = Integer.MIN_VALUE;
        for(Map.Entry<Integer,Integer>mp:map.entrySet()){
            int key = mp.getKey(),value = mp.getValue();
            if(freq>=value && key>=max){
                freq = value;
                max = key;
            }
        }
        return max;
    }
}
