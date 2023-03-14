class Solution {
public:
    int sumNumbersRecursion(TreeNode* root, int val) {
        // Base case
        if (root == nullptr) {
            return 0;
        }

        //1 left 1*10 + left->val = 12 return
        //sumNumbersRecursion(root->left, 1) == 12
        //1 right 1*10 + right->val 13 returb
        //sumNumbersRecursion(root->right, 1) == 13
        // return 12+13; done
        val = (val * 10 + root->val);

        // if current node is leaf, return the current value of val
        if (root->left == nullptr && root->right == nullptr) {
            return val;
        }

        // recur sum of values for left and right subtree
        return sumNumbersRecursion(root->left, val) +
            sumNumbersRecursion(root->right, val);
    }

    int sumNumbers(TreeNode* root) {
        return sumNumbersRecursion(root, 0);
    }
};
