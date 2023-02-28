class Solution {
public:

unordered_map<string,int>mp;
vector<TreeNode*>v;
string solve(TreeNode* root){

if(root==NULL)return "$";
string s="";


 s=s+to_string(root->val);
 s=s+"#"+solve(root->left);
 s=s+"#"+solve(root->right);

mp[s]++;

if(mp[s]==2){
   v.push_back(root);
}
return s;

}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
solve(root);
return v;

}
};
