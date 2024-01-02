class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {      
        Map<Integer,Integer> mp=new HashMap<>();
        Set<Integer> set=new HashSet<>();
        for(int i:nums)
        {
            set.add(i);
            mp.put(i,mp.getOrDefault(i,0)+1);
        }
        List<List<Integer>> answer=new ArrayList<>();
        while(mp.size()!=0)
        {
            List<Integer> list=new ArrayList<>();
            for(int i:set) {

                if(mp.containsKey(i))
                {
                    int val = mp.get(i);
                    if (val > 0) {
                        list.add(i);
                        mp.put(i, val - 1);
                    } else {
                        mp.remove(i);
                    }
                }
            }
            answer.add(list);
        }
        answer.remove(answer.size()-1);
        return answer;      
    }
}
