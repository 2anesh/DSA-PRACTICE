class Solution
{
    public:
        bool check(int n){ // checks if even(true) or false(odd)
            return n%2==0;
        }
        
        vector<int> findRange(int idx, bool chk,vector<int> a){
            int end = idx;
            while(end<a.size() and check(a[end]) == chk)end++;
            return {idx,end};
        }
        
        void sortRange(vector<int>&a , int start, int end){
            sort(a.begin()+start, a.begin()+end,greater<>());
        }
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            int idx = 0;
            while(idx<n){
                vector<int> range = findRange(idx,check(a[idx]),a);
                sortRange(a,range[0],range[1]);
                idx = range[1];
            }
            return a;
        }
};
