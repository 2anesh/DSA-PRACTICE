struct Node{
        Node *link[26];
      bool flag=false;
        bool containskey(char ch){
                return link[ch-'a']!=NULL;
        }
        void put(char ch,Node *node){
                link[ch-'a']=node;
        }
       Node *get(char ch){
                return link[ch-'a'];
        }
        void setend(){
            flag=true;    
        }
       bool isend(){
               return flag;
       }
};

class Solution {
        Node *root=new Node();
public:
        void insert(string word){
                Node *node=root;
                for(int i=0;i<word.size();i++){
                        if(!node->containskey(word[i])){
                           node->put(word[i],new Node());     
                        }
                      node=  node->get(word[i]);
                }
                node->setend();
        }
        bool search(string word){
        Node *node=root;
                for(int i=0;i<word.size();i++){
                        if(!node->containskey(word[i])){
                           return false;   
                        }
                        node=node->get(word[i]);
                }
                return node->isend();
                
        }
          vector<string> res;
    bool sol(string word, int count){
        if(count>1 && search(word))return true;
        for(int j=0;j<word.length()-1;j++){
            string left=word.substr(0,j+1);
            string right=word.substr(j+1);
            if(search(left) && sol(right, count+1)) return true;
            
        }
        return false;
    }
    
        
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       vector<string>ans;
            for(int i=0;i<words.size();i++){
                    insert(words[i]);
            }
			
		`	\\\sol check every word having two words or more if we check  so if it is means it is concatenated by these words`
			
            for(auto it:words){
                    if(sol(it,1)) ans.push_back(it);
            }
            return ans;
            
            
    }
};
