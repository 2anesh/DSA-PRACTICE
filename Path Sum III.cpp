class Solution {
private:
    void KSumPath(TreeNode* root, int targetSum , int &count, vector<int> path){
        if(root == NULL){
            return;
        }
        
        path.push_back(root->val);
        
        KSumPath(root->left , targetSum , count , path);
        KSumPath(root->right , targetSum , count , path);
        
        long int sum = 0; int size = path.size();
        for(int i = size-1 ; i >= 0 ; i--){
            sum += path[i];
            if(sum == targetSum)
            count++;
        }
        path.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector<int> path;
        KSumPath(root , targetSum , count ,path);
        return count;
    }
};
