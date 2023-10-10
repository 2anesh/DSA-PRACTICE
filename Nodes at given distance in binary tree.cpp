class Solution
{
private:

public:
    unordered_map<Node*,Node*>mp;
    Node *x=NULL;

    void InOrder(Node* root,int target){
        if(!root) return;
          if(root->data==target){
                x=root;
            }
        if(root->left){
            
            mp[root->left]=root;
            InOrder(root->left,target);
          
        } 
        
        if(root->right){
             mp[root->right]=root;
            InOrder(root->right,target);
        }
    }
    void Bfs(Node *root,int k, vector<int>&ans){
        queue<Node*>q;
        unordered_set<int>vis;
        vis.insert(root->data);
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            if(k==0){
                break;
            }
            while(n--){
                Node*temp=q.front();
                q.pop();
                if(temp->left && !vis.count(temp->left->data)){
                    q.push(temp->left);
                    vis.insert(temp->left->data);
                    
                }
                 if(temp->right && !vis.count(temp->right->data)){
                    q.push(temp->right);
                    
                    vis.insert(temp->right->data);
                    
                }
                 if( mp.count(temp) && !vis.count(mp[temp]->data)){
                    q.push(mp[temp]);
                    
                    vis.insert(mp[temp]->data);
                    
                }
            }
            k--;
          
        }
        while(!q.empty()){
            Node* tem=q.front();
            q.pop();
            ans.push_back(tem->data);
            
        }
        
        
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int>ans;  //ans vector to store result  
        InOrder(root,target); //Calculate the Inorder
        Bfs(x,k,ans);  //Calculate the Bfs
        sort(ans.begin(),ans.end()); //Sort the ans
        return ans;         
    }
};
