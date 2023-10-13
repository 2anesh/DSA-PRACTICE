class Solution{

public:
    void traverse(Node*root,int &ans,int x)
    {
        if(!root)return;
        traverse(root->left,ans,x);
        if(root->data <=x)ans =root->data;
        traverse(root->right,ans,x);
        
    }
    int floor(Node* root, int x) {
        int ans = -1;
        traverse(root,ans,x);
        return ans;
    }
};
