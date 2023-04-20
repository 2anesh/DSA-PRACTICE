class Solution{

    public:
    Node*findTarget(Node* root, int home, int k){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            if(temp->data==home){
                return temp;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
    void Parents(Node* root, unordered_map<Node*,Node*>&parents, Node *target,int home, int k){
         queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            if(temp->left){
                parents[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parents[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    
    
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        unordered_map<Node*,Node*>parents;
        Node*target = findTarget(root,home,k);
        Parents(root,parents,target, home,k);
        
        unordered_map<Node*,bool>vis;
        queue<Node*>q;
        q.push(target);
        vis[target]=true;
        int sum=0;
        int level=0;
        while(!q.empty()){
            int n = q.size();
            if(level>k){
                break;
            }
            level++;
            for(int i=0;i<n;i++){
                Node*curr = q.front();
                q.pop();
                sum+=curr->data;
                if(curr->left&&!vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right&&!vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parents[curr]&&!vis[parents[curr]]){
                    q.push(parents[curr]);
                    vis[parents[curr]]=true;
                }
            }
        }
        return sum;
    }


};
