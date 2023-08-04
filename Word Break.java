class Solution {
    public boolean helper(String s, int start, int end, HashSet<String> set, int[][] mem){
        if(start == end && start == s.length()) return true;
        String temp = s.substring(start, end+1);
        boolean res = false;

        if(mem[start][end] == 0){
            if(set.contains(temp)){
                // 2 options either to start new word from start+1, end+1
                // or include the character in 
                res = res || helper(s, end+1, end+1, set, mem) || helper(s, start, end+1, set, mem);
            }else{
                for(int i = end+1; i<=s.length(); i++){
                    if(set.contains(s.substring(start, i))){
                        res = res || helper(s, start, i-1, set, mem);
                    }
                }
            }

            // store res in mem 1 for true 2 for false;
            mem[start][end] = (res) ? 1: 2;
        }

        return (mem[start][end] == 1)?true:false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        // create a hashSet of all the words in list
        HashSet<String> set = new HashSet<>();
        for(String word : wordDict){
            set.add(word);
        }

        // 2d array for storing the result of start, end (memoisation)
        int[][] mem = new int[s.length()][s.length()];
        return helper(s, 0, 0, set, mem);
    }
}
