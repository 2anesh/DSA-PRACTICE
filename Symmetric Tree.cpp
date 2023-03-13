class Solution {
public:
    TreeNode* mirror(TreeNode*root)
    { if(root==NULL)
        return NULL;
        TreeNode*temp=new TreeNode();
        temp->left=temp->right=NULL;
        temp->val=root->val;
        if(root->left!=NULL)
        temp->right=mirror(root->left);
        if(root->right!=NULL)
        temp->left=mirror(root->right);
        return temp;

    }
    bool isIdentical(TreeNode*root,TreeNode*temp1)
    {
        if(root==NULL||temp1==NULL)
        return (root==temp1);
        return isIdentical(root->left,temp1->left)&&isIdentical(root->right,temp1->right)&&(root->val==temp1->val);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        return true;
        TreeNode*temp1=mirror(root);
         return isIdentical(root,temp1);

        
    }
};
