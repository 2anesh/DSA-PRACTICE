class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        long long x = 1,y = 1;
        vector<long long>v;
        while(n--){
            v.push_back(x);
            long long temp = y;
            y = y+x;
            x = temp;
            
        }
        return v;
    }
};
