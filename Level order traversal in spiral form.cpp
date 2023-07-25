vector<int> findSpiral(Node *root){
    vector<int> ans; 
    if(root==NULL) return ans; 
    queue<Node*> q; 
    q.push(root);  
    bool leftToRight=false; 
    while(!q.empty()){
        int sz=q.size(); 
        vector<int> temp; 
        for(int i=0;i<sz;i++){
            Node* node=q.front(); 
            q.pop(); 
            temp.push_back(node->data);
            if(node->left){
                q.push(node->left);
            } 
            if(node->right){
                q.push(node->right); 
            }
        }
        if(!leftToRight){
            reverse(temp.begin(),temp.end()); 
        } 
        for(auto it:temp){
            ans.push_back(it); 
        } 
        leftToRight=!leftToRight; 
        temp.clear(); 
    }  
    return ans; 
}
