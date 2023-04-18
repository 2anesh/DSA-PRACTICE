class Solution {
public:
    int ans=INT_MAX;
    int tar;
    
    //  <node,<sum,<flag,<min,max>>>>
    pair<int,pair<int,pair<bool,pair<int,int>>>> dfs(Node* node){
        bool flag=true;
        int mn=node->data, mx=node->data;
        int sum=node->data;
        int nodes=1;
        
        if(node->left){
            pair<int,pair<int,pair<bool,pair<int,int>>>> left=dfs(node->left);
            sum+=left.second.first;
            nodes+=left.first;
            if( left.second.second.first && (left.second.second.second.second < node->data) ){
                mn=left.second.second.second.first;
            } else {
                flag=false;
            }
        }
        if(node->right){
            pair<int,pair<int,pair<bool,pair<int,int>>>> right=dfs(node->right);
            sum+=right.second.first;
            nodes+=right.first;
            if( right.second.second.first && (right.second.second.second.first > node->data) ){
                mx=right.second.second.second.second;
            } else {
                flag=false;
            }
        }

        if(flag && sum==tar){
            ans=min(ans, nodes);
        }
        return {nodes,{sum,{flag,{mn,mx}}}};
    }
    
    int minSubtreeSumBST(int target, Node *root) {
        tar=target;
        dfs(root);
        return ans==INT_MAX?-1:ans;
    }
};
