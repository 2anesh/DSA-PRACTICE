class Solution {
    vector<int> x;
    vector<int> y;
public:
    void printLeaf(TreeNode* root, vector<int> &k) {
        if(root == NULL) return;
        printLeaf(root->left, k);
        if(root->left == NULL && root->right == NULL) k.push_back(root->val);
        printLeaf(root->right, k);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        printLeaf(root1, x);
        printLeaf(root2, y);
        return x==y;
    }
};
