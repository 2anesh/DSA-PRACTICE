class Solution {
public:
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* prev = NULL;
    
    void inOrder(struct Node* root){
        if(root == NULL){
            return;
        }
        inOrder(root->left);
        if(prev != NULL && root->data < prev->data){
            if(first == NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;
        inOrder(root->right);
    }
    
    struct Node* correctBST(struct Node* root) {
        inOrder(root);
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
        return root;
    }
};
