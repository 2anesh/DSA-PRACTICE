class Solution{
public:
int child_sum(Node *root)
{
    if(root==NULL) return 0;
    if(root->left&&root->right)
    return root->data+min(child_sum(root->left),child_sum(root->right));
    else if(root->left)
    return root->data+child_sum(root->left);
    else if(root->right)
     return root->data+child_sum(root->right);
     else
     return root->data;
}
int f(Node *root,int target,int sum)
{
    if(root==NULL) return -1;
    if(root->data==target)
    {
        int minn = child_sum(root)-root->data;
        return sum-minn;
    }
    if(root->data>target)
    return f(root->left,target,sum+root->data);
    else return f(root->right,target,sum+root->data);
}
    int maxDifferenceBST(Node *root,int target){
        // Code here
        return f(root,target,0);
    }
};
