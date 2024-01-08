class Solution {
public:
    int calculate_sum(TreeNode* root,int low,int high)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->val < low || root->val > high)
        {
            return 0 + calculate_sum(root->left,low,high) + calculate_sum(root->right,low,high);
        }
        else
        {
            return root->val + calculate_sum(root->left,low,high) + calculate_sum(root->right,low,high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return calculate_sum(root,low,high);
    }
};
