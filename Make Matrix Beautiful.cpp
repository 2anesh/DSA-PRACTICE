class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
     int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> r , c;
        int co= 0;
        
        for(int i = 0; i < n ; i++)
        {
            int sum = 0;
            for(int j = 0; j < n; j++)
            {
                sum = sum + matrix[i][j];
            }
            r.push_back(sum);
        }
        
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = 0; j < n; j++)
            {
                sum = sum + matrix[j][i];
            }
            c.push_back(sum);
        }
        
        
        int rm = *max_element(r.begin() , r.end());
        int cm = *max_element(c.begin() , c.end());
        
        if(rm > cm)
        {
            for(int i = 0; i < r.size(); i++)
            {
                co = co + rm - r[i];
            }
        }
        else{
            
               for(int i = 0; i < r.size(); i++)
            {
                co = co + cm - r[i];
            }
            
        }
        
        return co;
        
    } 
};
