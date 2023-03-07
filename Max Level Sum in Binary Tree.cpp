class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        // Your code here
        if(root==NULL)
            return 0;
        queue<Node*> q;
        q.push(root);
        int su = root->data;
        while(!q.empty()){
            int tsum = 0;
            int sz = q.size();
            while(sz--){
                if(q.front()->left!=NULL)
                    q.push(q.front()->left);
                if(q.front()->right!=NULL)
                    q.push(q.front()->right);
                tsum += (q.front())->data;
                q.pop();
            }
            su = max(su, tsum);
        }
        return su;
    }
};
