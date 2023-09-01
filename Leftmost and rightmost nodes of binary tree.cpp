void printCorner(Node *root)
{
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node*node=q.front();
            q.pop();
            if(i==0||i==n-1){
                cout<<node->data<<" ";
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
}
