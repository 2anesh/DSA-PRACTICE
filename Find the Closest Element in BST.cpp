class Solution
{
    
    public:
    int distance=100000;//the answer to our problem

//using inorder traversal to get the data of each node of tree 

//Also taking the minimum of the above distance and absolute distance between current node data and given value k.

    void inorder(Node*root,int K){
        if(root!=NULL){
            inorder(root->left,K);
            distance=min(distance,abs(root->data-K));
            inorder(root->right,K);
        }
    }
    //Function to find the least absolute difference between any node
    //value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        
        if(root!=NULL){
            inorder(root,K);
        }
        return distance;
    }
};
