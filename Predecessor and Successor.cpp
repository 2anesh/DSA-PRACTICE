class Solution
{
    public:
    void minimum(Node* root, Node*& pre, Node*& suc, int key){
        if(root==NULL) return;
        
        
        if(root->key==key){
            //find pre, first go left and then keep going right


            if(root->left!=NULL){
                Node*temp=root->left;
                while(temp->right)
                  temp=temp->right;
                pre=temp;
            }
            //find suc, first go right and then keep going left


            if(root->right!=NULL){
                Node*temp=root->right;
                while(temp->left)
                  temp=temp->left;
                suc=temp;
            }
            return;
        }

        if(root->key > key){
            suc=root;
            minimum(root->left, pre, suc,key);
        }
        else{
            pre=root;
            minimum(root->right, pre, suc, key);
        }
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
                minimum(root,pre,suc,key);
    }
};
