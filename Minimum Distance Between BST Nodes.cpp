class Solution {
public:
int ans=INT_MAX;
void func(TreeNode* root, int &prev, int &next){
    if(root==NULL){
        return;
    }
    else{
        func(root->left, prev, next);
        if(prev!=-1){
            next=min(next, abs(root->val-prev));
        }
        prev=root->val;
        func(root->right, prev, next);
    }
}
int minDiffInBST(TreeNode* root) {
    int prev=-1, next=INT_MAX;
    func(root, prev, next);
    return next;
}
};
