class Solution {
public:

    bool isBalanced(Node* root) {
        if (root == NULL) {
            return true; 
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }

        return false;
    }

    int getHeight(Node* node) {
        if (node == NULL) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return 1 + max(leftHeight, rightHeight);
    }
};
