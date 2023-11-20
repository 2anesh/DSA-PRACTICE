class Solution{
    int ans,k,sum;
    map<int,int> mp;
    void rec(Node *root){
        if(!root)
            return;
        sum+=root->data;
        ans+=mp[sum-k];
        mp[sum]++;
        rec(root->left);
        rec(root->right);
        if(--mp[sum]==0) mp.erase(sum);
        sum-=root->data;
    }
  public:
    int sumK(Node *root,int K){
        // code here 
        ans = 0,k=K,sum=0;
        mp[0]=1;
        rec(root);
        return ans;
    }
};
