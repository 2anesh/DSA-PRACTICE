class Trie
{
    Trie arr[] = new Trie[26];
    boolean isComp = false; 
}

class Solution{
    
    Trie root = new Trie();
    
    public void makeTrie(String str)
    {
        Trie temp = root;
        
        for(char x : str.toCharArray())
        {
            Trie node = new Trie();
            int ind = x-'0'-17;
            temp.arr[ind] = node;
            temp = temp.arr[ind];
        }
        temp.isComp = true;
    }
    
    public boolean searchTrie(String str)
    {
        Trie temp = root;
        for(char x : str.toCharArray())
        {

            if(x<'A' || x>'Z')
                 continue;
                 
            int ind = x-'0'-17;
            temp = temp.arr[ind];

            if(temp == null)
                break;
            
            if(temp.isComp) return true;
        }
        return false;
    }
    
    ArrayList<String> CamelCase(int N,String[] Dictionary,String Pattern){
        
        ArrayList<String> ans = new ArrayList<>();
        
        makeTrie(Pattern);
        
        for(String str :Dictionary)
        {
            if(searchTrie(str))
                ans.add(str);
        }
        
        if(ans.size() == 0)
            ans.add("-1");
        
        Collections.sort(ans);
        
        return ans;
    }
}
