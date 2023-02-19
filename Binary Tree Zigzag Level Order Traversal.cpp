class Solution 
{
 public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root==NULL)
          return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                ans.push_back(v);
                if(!q.empty())
                {
                    q.push(NULL);
                    v.erase(v.begin(),v.end());
                }
            }
            else
            {
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        for(int i=0;i<ans.size();i++)
        {
           if(i%2)
              reverse(ans[i].begin(),ans[i].end());
        }
      return ans;	
    }
};
