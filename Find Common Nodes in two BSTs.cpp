class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    void helper(Node *root,unordered_map<int,int>&mp)
    {
        if(root) {
            helper(root->left,mp);
            mp[root->data]++;
            helper(root->right,mp);
        }
    }
    void helper2(Node *root2, unordered_map<int, int>&mp,vector<int>&ans)
    {
        if(root2) {
            helper2(root2->left,mp,ans);
            if(mp.find(root2->data) != mp.end()) ans.push_back(root2->data);
            helper2(root2->right,mp,ans);
            
        }
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     unordered_map<int,int> mp;
     vector<int> ans;
     helper(root1,mp);
     helper2(root2,mp,ans);
     return ans;
    }
};
