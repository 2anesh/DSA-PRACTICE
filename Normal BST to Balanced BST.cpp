class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    void inorder(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    Node* buildtree(vector<int> &ans,int left,int right){
        if(left > right){
            return NULL;
        }
        else{
            int mid= (left + right)/2;
            Node* root=new Node(ans[mid]);
            root->left=buildtree(ans,left,mid-1);
            root->right=buildtree(ans,mid+1,right);
            
        }
    }
    Node* buildBalancedTree(Node* root)
    {
        // Code here
        vector<int> ans;
        inorder(root,ans);
        
        return buildtree(ans,0,ans.size()-1);
        
    }
};
