class TrieNode{
    char data;
    TrieNode[] nodes = new TrieNode[26];
    boolean isLastNode = false;
    public TrieNode(char c){
        this.data = c;
    }
}

class Trie {
    TrieNode root;

    public Trie() {
        root = new TrieNode('\0');
    }

    public void insertUtil(TrieNode root,String word){
        // base case 
        if(word.length() == 0){
            // make the last node as true
            root.isLastNode = true;
            return ;
        }

        TrieNode child;

        int tempIdx = word.charAt(0) - 'a';

        // search is the root has this character set
        if(root.nodes[tempIdx] != null){
            child = root.nodes[tempIdx];
        }else{  
            child = new TrieNode(word.charAt(0));
            root.nodes[tempIdx] = child;
        }

        insertUtil(child, word.substring(1));
    }
    
    public void insert(String word) {
        insertUtil(root, word);
    }
    
    public boolean searchUtil(TrieNode root, String word){
        // base case
        if(word.length() == 0){
            // check if the last node is set 
            return root.isLastNode;
        }

        TrieNode child;

        int tempIdx = word.charAt(0) - 'a';

        if(root.nodes[tempIdx] != null){
            child = root.nodes[tempIdx];
        }else{
            return false;
        }

        return searchUtil(child, word.substring(1));
    }
    public boolean search(String word) {
        return searchUtil(root, word);
    }
    
    public TrieNode findDivergent(TrieNode root, String word){
        // base case
        if(word.length() == 0){
            return root;
        }

        TrieNode child;

        int tempIdx = word.charAt(0) -'a';

        if(root.nodes[tempIdx] != null){
            child = root.nodes[tempIdx];
        }else{
            return null;
        }

        return findDivergent(child, word.substring(1));
    }

    public boolean startsWithUtil(TrieNode root){
        if(root.isLastNode) return true;

        boolean res = false;
        for(int i = 0; i<26; i++){
            if(root.nodes[i]!=null){
                res = res || startsWithUtil(root.nodes[i]);
            }
        }

        return res;
    }
    public boolean startsWith(String prefix) {
        TrieNode div = findDivergent(root, prefix);
        if(div == null) return false;
        // System.out.println(div.data);
        return startsWithUtil(root);
    }
}
