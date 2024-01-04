class Solution {
    static int singleElement(int[] arr , int N) {
        // code here
       HashMap<Integer, Integer> hm = new HashMap<>();
       for(int i=0;i<N; i++){
           if(!hm.containsKey(arr[i])){
               hm.put(arr[i],1);
           }    else{
               Integer a = hm.get(arr[i]);
               hm.put(arr[i],a.intValue() + 1);
           }
           
       }
        for(Map.Entry<Integer, Integer> entry : hm.entrySet()){
            if(entry.getValue() == 1){
                return entry.getKey();
            }
        }
            return -1;
   }
}
