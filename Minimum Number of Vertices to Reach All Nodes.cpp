class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        ///IF INDEGREE=0 then it means that set of vertices able  to reach each nodes
        vector<int>ans;
        vector<int>indegree(n,0);

        for(auto it:edges){
           indegree[it[1]]+=1;///as indegree={0,1}, 1 considered as 2nd element
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0)ans.push_back(i);
        }
        return ans;
    }
};
