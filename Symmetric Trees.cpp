class Solution{
    public:
    bool solve(struct Node* root1,struct Node* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL && root2 != NULL){
            return false;
        }
        if(root1 != NULL && root2 == NULL){
            return false;
        }
        
        bool lef = solve(root1->left,root2->right);
        bool rig = solve(root1->right,root2->left);
        
        if(root1->data == root2->data && lef && rig){
            return true;
        }
        return false;
    }
    bool isSymmetric(struct Node* root){
        return solve(root,root);
    }
};
