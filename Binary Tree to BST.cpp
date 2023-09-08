class Solution{
  public:
    
    void traverse(Node* root,  priority_queue <int, vector<int>, greater<int>> &pq){
        if(!root) return;
        pq.push(root->data);
        traverse(root->left, pq);
        traverse(root->right, pq);
    }
    
    void inorder(Node* root,  priority_queue <int, vector<int>, greater<int>> &pq){
        if(!root) return;
        inorder(root->left, pq);
        root->data = pq.top();
        pq.pop();
        inorder(root->right, pq);
    }
    
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        priority_queue <int, vector<int>, greater<int>> pq;
        
        // traverse the binary tree and push the elements in the priority queue
        traverse(root, pq);
        
        // traverse the tree again in inordered manner and use the pq to assign the elements in sorted manner
        inorder(root, pq);
        return root;
        
    }
};
