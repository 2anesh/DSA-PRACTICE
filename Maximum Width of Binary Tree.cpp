class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       int max_width=1;
       deque<pair<TreeNode*,unsigned int >>dq;
       dq.push_back({root,1});

       while(!dq.empty()){
            if(max_width<((dq.back().second)-(dq.front().second)+1)){
                 max_width=((dq.back().second)-(dq.front().second)+1);
            }
            int size_of_dq=dq.size();
           while(size_of_dq-->0){
             auto node=dq.front();
            
             dq.pop_front();
            if((node.first)->left!=NULL){
                dq.push_back({(node.first)->left,2*node.second});
            }
            if((node.first)->right!=NULL){
               dq.push_back({(node.first)->right,2*node.second+1});
            }
           }
       }  
       return max_width;     
    }
};
