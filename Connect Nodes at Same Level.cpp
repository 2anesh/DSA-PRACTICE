class Solution{
    public:
    void connect(Node *root)
    {
       // Code Here
       queue<Node *> q;
       
       q.push(root);
       
       while(!q.empty())
       {
           int n = q.size();
           vector<Node* > temp;
           
           Node* conn = NULL;
           
           for(int i = 0; i < n ; i++)
           {
               
               auto f = q.front();
               q.pop();
               
               
               if(f->left) q.push(f->left);
               if(f->right) q.push(f->right);
               
               if(i == 0)
               {
                   conn = f;
               }
               
               else
               {
                   conn->nextRight = f;
                   conn = f;
               }
           }
           
         
       }
    }    
};
