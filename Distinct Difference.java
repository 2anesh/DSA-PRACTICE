class Solution {
    public static ArrayList<Integer> getDistinctDifference(int N, int[] A) {
        // code here
        Map<Integer,Integer> prev = new HashMap<>();
        Map<Integer,Integer> next = new HashMap<>();
        
        for(int i : A){
            next.put(i, next.getOrDefault(i,0)+1);
        }
        
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0;i < N;i++){
            if(next.get(A[i]) > 1){
                int val = next.get(A[i]);
                next.put(A[i], val-1);
            }else{
                next.remove(A[i]);
            }
            int left = prev.size();
            int right = next.size();
            
            prev.put(A[i], prev.getOrDefault(A[i],0)+1);
            list.add(left-right);
        }
        
        return list;
    }
}
