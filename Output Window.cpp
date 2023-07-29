void in__(struct Node* root, vector<int> *__)
{
    if(root)
    {
        in__(root->left, __);
        __->push_back(root->data);
        in__(root->right, __);
        
    }
}
float findMedian(struct Node *root)
{
      //Code here
      vector<int> __;
      in__(root, &__);
      int n = __.size();
      if(n % 2 != 0)
      {
          return __[n / 2];
      }
      return (__[n / 2] + __[(n / 2) - 1]) / 2.0;
}
