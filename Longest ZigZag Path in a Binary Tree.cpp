class Solution {
public:

    void dfs(TreeNode* root, int pleft, int pright,int &ans){
        if(root==NULL) return ;
        if(root->right){
            ans = max(ans, pleft+1);
            dfs(root->right, 0, pleft+1,ans);
        }
        if(root->left){
            ans = max(ans, pright+1);
            dfs(root->left, pright+1, 0,ans);
            
        }
    }
    int longestZigZag(TreeNode* root) {
    int ans=0;
        dfs(root, 0, 0,ans);
        return ans;
    }
};
