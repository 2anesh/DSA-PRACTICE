int iKthAncestor(Node * root, int k, int node, int &result){
    if(root==NULL) return 0;
    else{
        if(root->data==node) return 1;
        int i=iKthAncestor(root->left, k, node,result);
        int j=iKthAncestor(root->right, k, node,result);
        int sum=i+j;
        if(sum==0) return 0;
        else if(k==sum && result==-1) result=root->data;
        return sum+1;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    int result=-1;
    iKthAncestor(root, k, node,result);
    return result;
}
