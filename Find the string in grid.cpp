class Solution {
public:
    vector<vector<int>> dirs;
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int m=grid.size();
	    int n=grid[0].size();
	    int l=word.size();
	    vector<vector<int>> ans;
	    dirs={{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1},{1,0},{-1,0}};
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++){
	            if(word[0]!=grid[i][j])continue;
	            if(dfs(grid,m,n,word,l,i,j))ans.push_back({i,j});
	        }
	    }
	    return ans;
	}
	int dfs(vector<vector<char>>& grid,int m,int n,string word,int l,int i,int j){
	    for(auto it:dirs){
	        int k=0;
	        for(int r=i,c=j;min(r,c)>=0 && r<m && c<n && k<l && grid[r][c]==word[k];k++,r+=it[0],c+=it[1]);
	        if(k==l)return 1;
	    }
	    return 0;
	}
   
};
