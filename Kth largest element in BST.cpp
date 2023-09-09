class Solution
{
    public:
    
       void reverse_inorder( Node * root , vector<int> &ans){
           
           if(root == NULL){
               return;
           }
           
           reverse_inorder(root->right , ans);
           ans.push_back(root->data);
           reverse_inorder(root->left , ans);
       }
    int kthLargest(Node *root, int K)
    {
       vector<int> ans;                       // it is very simple question and we can solve this question
                                             // in two way 1.reverse_inorder traversal and store the data in Descending Order
       reverse_inorder(root , ans);          // where the k largest element is present on k - 1 index of vector 
                                              // 2. By useing Max Priority Queue and store the root data in Max heap
                                              // After store data pop(); k-1  element for Max heap and return top of Priority Queue 
       if( K > ans.size()){                   // Notice -: Might the time - complexity will increase in second approach.
           return -1;
       }
       
       return ans[K-1];
    }
};
