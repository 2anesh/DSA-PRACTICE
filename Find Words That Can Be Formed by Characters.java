class Solution {
    public int countCharacters(String[] words, String chars) {
        int count = 0;
        for(int i=0;i<words.length;i++)
        {
        HashMap<Character,Integer> hm = new HashMap<Character,Integer>();
        for(int j=0;j<chars.length();j++)
        {
            hm.put(chars.charAt(j),hm.getOrDefault(chars.charAt(j),0)+1);
        }
            int k=0;
            for(int j=0;j<words[i].length();j++)
            {
                if(hm.get(words[i].charAt(j))!=null&&hm.get(words[i].charAt(j))>0)
                {k++;
                hm.put(words[i].charAt(j),hm.get(words[i].charAt(j))-1);
                }
            }
            if(k==words[i].length())
            count = count+words[i].length();
        }
        return count;
    }
}
