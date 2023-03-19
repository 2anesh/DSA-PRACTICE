struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch -'a'] != NULL);
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

};


class WordDictionary {

    private:
        Node* root;
public:
    WordDictionary() {
        root = new Node();

        for(int i = 0; i < 26; i++)
        {
            root->links[i] = NULL;
        }
    }
    
    void addWord(string word) {

        Node* node = root;

        int n = word.length();

        for(int i = 0; i < n; i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
        
    }

    bool searchUtil(string word, int i, Node* node)
    {
        if(i == word.size())
        {
            return node->isEnd();
        }

        if(word[i] != '.')
        {
            if(node->containsKey(word[i]))
            {
                return searchUtil(word, i+1, node->get(word[i]));
            }
        }
        else
        {
            // word[i] is '.'
            for(int j = 0; j < 26; j++)
            {
                if(node->links[j] != NULL && 
                searchUtil(word, i+1, node->links[j]) == true)
                    return true;
            }
        }

        return false;
    }
    
    bool search(string word) {

        return searchUtil(word, 0, root);
        
    }
};
