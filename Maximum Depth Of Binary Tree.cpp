class Solution{
  private:
  int solve(Node *root,int x)
  {
      if(root==NULL)
      {
         return 0; 
      }
      else
      {
          x=1+ max(solve(root->left,x),solve(root->right,x));
      }
      return x;
  }
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        int maxd=0;
        return solve(root,maxd);
    }
};
