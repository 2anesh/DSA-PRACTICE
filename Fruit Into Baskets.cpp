class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int i = 0, j = 0, k = 2, sz = fruits.size(), maxm = 0 ;
        unordered_map<int, int> umap ;
        
        while(j<sz)
        {
            umap[fruits[j]]++ ;
            
            if(umap.size() <= k)
            {
                maxm = max(maxm, j-i+1) ; j++ ;
            }
            else if(umap.size() > k)
            {
                while(umap.size() > k)
                {
                    umap[fruits[i]]-- ;
                    if(umap[fruits[i]] == 0){ umap.erase(fruits[i]) ; }
                    i++ ;
                }
                j++ ;
            }
        }
        return maxm ;
    }
};
