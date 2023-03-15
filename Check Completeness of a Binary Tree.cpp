class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            TreeNode* t  = q.front();
            q.pop();
            if(t==NULL)
            {
                flag=true;
            }
            else
            {
                if(flag)
                {
                    return false;
                }
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};
