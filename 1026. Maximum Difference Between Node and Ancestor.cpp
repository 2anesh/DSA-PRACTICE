class Solution {
public:
    int maxDiff = INT_MIN ;
    int maxAncestorDiff(TreeNode* root) {      
        if(root == NULL) return 0 ;
        findMax(root , root ) ;
        maxAncestorDiff(root->left) ;
        maxAncestorDiff(root->right) ;
        return maxDiff ;
    }
    void findMax(TreeNode* ancestor , TreeNode* child ) {
        if(ancestor == NULL) return ;
        if(child == NULL) return ;
        int difference = abs(child->val -  ancestor->val ) ;
        maxDiff = max(maxDiff , difference) ;
        findMax(ancestor , child->left) ;
        findMax(ancestor , child->right) ;
    }
};
