class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        Arrays.sort(arr);
        HashMap<Integer, Long> map = new HashMap<>();

        for(int a : arr){
            long temp = 1;
            for(int b : arr){
                if(b > a) break;
                if(a%b == 0 && map.containsKey(a / b)){
                    temp += map.get(b) * map.get(a / b);
                }
            }
            map.put(a, temp);
        }

        long result = 0;
        for(long x : map.values()){
            result += x;
        }

        return (int)(result % 1000000007);
    }
}
