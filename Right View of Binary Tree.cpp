class Solution

{

    public:

    //Function to return list containing elements of right view of binary tree.

    void solve(Node *root, vector<int>& ans, int level){

        if(root==NULL){

            return;

        }

        

        if(ans.size()==level){

            ans.push_back(root->data);

        }

        

        solve(root->right, ans, level+1);

        solve(root->left, ans, level+1);

    }

    vector<int> rightView(Node *root)

    {

      vector<int> ans;

      int level=0;

      solve(root, ans, level);

      return ans;

    }

};

